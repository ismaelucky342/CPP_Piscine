# CPP Module 06 - C++ Casts

- **Rank:** 05
- **Language:** C++98
- **Subject:** [subjects/cpp06.pdf](../subjects/cpp06.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 06 is about explicit conversions. C++ offers four named casts, and each one expresses a different intent. The exercises cover scalar type conversion, pointer-to-integer serialization and runtime type identification without `<typeinfo>`.

The module is short but conceptually dense: it separates conversions that are safe, conversions that are checked at runtime and conversions that simply reinterpret bits.

## Learning objectives

- Detect the type of a scalar literal.
- Convert between `char`, `int`, `float` and `double`.
- Handle overflow, non-displayable characters and special floating-point values.
- Use `static_cast`, `reinterpret_cast` and `dynamic_cast` appropriately.
- Serialize a pointer to `uintptr_t` and back.
- Identify a dynamic type without using `typeinfo`.

## Key concepts

### The four casts

- `static_cast<T>(value)`: compile-time conversion between related types.
- `dynamic_cast<T>(value)`: runtime-checked conversion in a polymorphic hierarchy; requires RTTI and a polymorphic source type.
- `reinterpret_cast<T>(value)`: reinterpretation of the bit pattern; used for pointer/integer round-trips.
- `const_cast<T>(value)`: adds or removes `const`/`volatile`.

C-style casts are deliberately avoided because they hide which conversion is happening.

### Scalar conversion

A literal can be a `char` (for example `'a'`), an `int`, a `float` (suffix `f`) or a `double`. Special values `-inff`, `+inff`, `nanf`, `-inf`, `+inf` and `nan` must be accepted.

When a conversion is impossible or overflows, print `impossible`. When a char conversion produces a non-displayable character, print `Non displayable`.

### Pointer serialization

`uintptr_t` is an unsigned integer type large enough to hold a pointer. Serializing a pointer means converting it to `uintptr_t`; deserializing means converting it back. The round-trip must return the original address.

### Runtime type identification without `typeinfo`

`dynamic_cast<A*>(basePtr)` returns a valid pointer only when the dynamic type is `A` (or derives from it). The reference version throws `std::bad_cast` on failure. This is enough to implement `identify()` without including `<typeinfo>`.

## Exercises

### ex00 - Conversion of scalar types

- **Directory:** `ex00/`
- **Files:** `Makefile`, `*.cpp`, `*.{h,hpp}`
- **Authorized:** any function that converts a string to an `int`, `float` or `double`.
- Write `ScalarConverter` with a single static method:

```cpp
static void convert(std::string const& literal);
```

- The class must not be instantiable.
- Detect the literal type, convert it to `char`, `int`, `float` and `double`, and print all four values.
- Handle `-inff`, `+inff`, `nanf`, `-inf`, `+inf` and `nan`.
- Handle overflow and invalid literals.
- Print `Non displayable` for a non-displayable char and `impossible` for a failed conversion.

Example:

```text
$> ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
$> ./convert nan
char: impossible
int: impossible
float: nanf
double: nan
$> ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

### ex01 - Serialization

- **Directory:** `ex01/`
- **Files:** `Makefile`, `*.cpp`, `*.{h,hpp}`
- `Serializer` is not instantiable and provides:

```cpp
static uintptr_t serialize(Data* ptr);
static Data* deserialize(uintptr_t raw);
```

- `Data` must be a non-empty structure with real data members.
- Serialize the address of a `Data` object, deserialize the result and verify that both pointers are equal.
- This is the canonical use case for `reinterpret_cast`.

### ex02 - Identify real type

- **Directory:** `ex02/`
- **Files:** `Makefile`, `*.cpp`, `*.{h,hpp}`
- **Forbidden:** `std::typeinfo` and the `<typeinfo>` header.
- `Base` has a public virtual destructor.
- `A`, `B` and `C` inherit publicly from `Base` and are empty.
- `Base* generate()` randomly creates an `A`, `B` or `C`.
- `void identify(Base* p)` prints `A`, `B` or `C`.
- `void identify(Base& p)` does the same without using a pointer inside the function.
- The pointer version uses `dynamic_cast` on pointers.
- The reference version uses `dynamic_cast` on references and catches `std::bad_cast`.

## Build and run

```bash
cd CPP_Module_06/ex00 && make && ./ex00 42.0f
cd CPP_Module_06/ex01 && make && ./ex01
cd CPP_Module_06/ex02 && make && ./ex02
```

## Evaluation notes

- `ScalarConverter`, `Serializer` and `Base` must not be instantiable where the subject requires it.
- Do not use C-style casts.
- Do not include `<typeinfo>` in `ex02`.
- Handle `nan`, `inf`, overflow and non-displayable characters.
- The `Data` structure must have real members; an empty struct is not accepted.
- The pointer round-trip must return exactly the original address.
- STL containers and algorithms are forbidden.
