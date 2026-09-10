# C++ Module 06 — C++ Casts

This project contains the three exercises from **C++ Module 06**, focused on the main C++ cast operators and runtime type identification.

The project follows the **C++98** standard and is intended to be compiled with `c++ -Wall -Wextra -Werror`.

## Requirements

- C++98
- `c++`
- `-Wall -Wextra -Werror`
- No external libraries
- No C++11 (or later) features

The module also forbids `using namespace`, `friend`, C allocation/printing functions such as `malloc`, `free` and `printf`, and STL containers/algorithms before Modules 08 and 09.

---

## Project structure

```text
CPP_Module_06/
├── README.md
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── includes/
│   │   └── ScalarConverter.hpp
│   └── src/
│       └── ScalarConverter.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── includes/
│   │   ├── Data.hpp
│   │   └── Serializer.hpp
│   └── src/
│       └── Serializer.cpp
└── ex02/
    ├── Makefile
    ├── main.cpp
    ├── includes/
    │   ├── Base.hpp
    │   ├── A.hpp
    │   ├── B.hpp
    │   └── C.hpp
    └── src/
        └── Base.cpp
```

Each exercise is built independently from its own directory.

---

# Exercise 00 — Conversion of scalar types

## Objective

The goal of this exercise is to use **`static_cast`** for explicit conversion between scalar types.

The program receives a string representation of a C++ scalar literal and displays its value as:

- `char`
- `int`
- `float`
- `double`

The conversion class is not instantiable and exposes a single static entry point:

```cpp
class ScalarConverter
{
public:
    static void convert(const std::string& literal);
};
```

The implementation first determines the kind of literal received and then performs the required scalar conversions.

## Supported forms

### Character literals

Examples:

```text
a
z
*
```

### Integer literals

```text
0
42
-42
```

### Float literals

```text
0.0f
42.0f
-4.2f
```

### Double literals

```text
0.0
42.0
-4.2
```

### Pseudo-literals

```text
nan
+inf
-inf

nanf
+inff
-inff
```

The program reports `impossible` when a conversion cannot be performed or when the resulting value cannot be represented by the destination type. Non-displayable character results are reported as `Non displayable`.

## Build and run

```bash
cd ex00
make
./ex00 42.0f
```

Example format:

```text
char: '*'
int: 42
float: 42.0f
double: 42.0
```

The exercise can also be rebuilt from scratch with:

```bash
make re
```

---

# Exercise 01 — Serialization

## Objective

The goal of this exercise is to use **`reinterpret_cast`** to convert a pointer to an integer type and then convert that integer back to the original pointer type.

A non-empty `Data` structure is used as the object being serialized.

```cpp
struct Data
{
    int value;
};
```

The conversion class is not instantiable and exposes:

```cpp
class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
```

## Conversion flow

```text
Data* ──reinterpret_cast──> uintptr_t

uintptr_t ──reinterpret_cast──> Data*
```

The test program serializes the address of a `Data` object, deserializes it and verifies that the restored pointer compares equal to the original pointer.

## Build and run

```bash
cd ex01
make
./ex01
```

Example format:

```text
original:  <address>
restored:  <address>
value:     42
Pointers are equal
```

---

# Exercise 02 — Identify real type

## Objective

The goal of this exercise is to use **`dynamic_cast`** to identify the runtime type of an object through a polymorphic base class.

The hierarchy consists of:

```text
        Base
       / | \
      A  B  C
```

`Base` contains a public virtual destructor. `A`, `B` and `C` publicly inherit from `Base`.

## Object generation

The following function randomly creates one of the three derived types and returns it as a `Base*`:

```cpp
Base* generate(void);
```

## Pointer identification

```cpp
void identify(Base* p);
```

This version uses `dynamic_cast` with pointers and checks whether each cast returns a null pointer.

## Reference identification

```cpp
void identify(Base& p);
```

This version uses `dynamic_cast` with references. A failed cast is detected through the exception mechanism and handled with `try`/`catch`.

Pointers are not used inside this overload.

The exercise does not use `<typeinfo>`.

## Build and run

```bash
cd ex02
make
./ex02
```

Example output:

```text
A
C
B
```

The order depends on the randomly generated types.

---

# Makefile commands

Each exercise provides the standard targets:

```bash
make
make clean
make fclean
make re
```

- `make`: builds the exercise.
- `make clean`: removes object files.
- `make fclean`: removes object files and the executable.
- `make re`: performs a full rebuild.

---

# Compilation flags

All exercises use:

```text
-Wall -Wextra -Werror -std=c++98
```

The code is intended to remain compatible with the C++98 language standard and to avoid features introduced in later C++ versions.
