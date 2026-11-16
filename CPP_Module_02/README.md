# CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading and the Orthodox Canonical Form

<img width="917" height="218" alt="CPP Module 02" src="https://github.com/user-attachments/assets/69920d8b-9531-4f03-a01f-e4c736bb86b1" />

- **Rank:** 04
- **Language:** C++98
- **Subject:** [subjects/cpp02.pdf](../subjects/cpp02.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 02 introduces the **Orthodox Canonical Form** (OCF) and operator overloading through a fixed-point number class called `Fixed`. This is the first module in which every class must be a complete value type: default constructor, copy constructor, copy assignment operator and destructor.

The fixed-point representation uses an integer to store the value and a fixed number of fractional bits. It is a good excuse to practise bit shifting, rounding, `const` correctness and operator overloading.

## Learning objectives

- Implement the four canonical member functions.
- Understand when the compiler-generated versions are wrong.
- Represent fractional values with integers.
- Overload comparison, arithmetic and increment/decrement operators.
- Implement `const` and non-const overloads of `min` and `max`.
- Use `roundf` correctly.
- Build a small geometric algorithm on top of a value type.

## Key concepts

### Orthodox Canonical Form

A class in OCF provides:

1. a default constructor;
2. a copy constructor;
3. a copy assignment operator;
4. a destructor.

For a class that owns no resources the four functions may be trivial, but they must still exist and behave correctly. For a class that owns memory, the copy operations must be deep.

### Fixed-point arithmetic

`Fixed` stores `raw` as an integer. With 8 fractional bits:

- `value = raw / 256.0f`;
- converting from `int`: `raw = value << 8`;
- converting from `float`: `raw = roundf(value * 256.0f)`;
- converting back to `int`: `raw >> 8`.

Fixed-point values are deterministic and avoid floating-point rounding surprises, at the cost of range and precision.

### Operator overloading

Overloading lets a user-defined type behave like a built-in type:

```cpp
Fixed a(10);
Fixed b(2.5f);
if (a > b)
    std::cout << a + b << std::endl;
```

The insertion operator `<<` must be a non-member function because its left operand is a stream.

## Exercises

### ex00 - My First Class in Orthodox Canonical Form

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
- **Private members:** an integer raw value and a static constant integer number of fractional bits equal to 8.
- **Public members:** default constructor (value 0), copy constructor, copy assignment operator, destructor, `getRawBits() const` and `setRawBits(int const raw)`.
- Constructors, the assignment operator and `getRawBits()` print messages so the evaluator can see when they are called.

Expected behaviour:

```text
Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
...
0
0
0
Destructor called
Destructor called
Destructor called
```

### ex01 - Towards a more useful fixed-point number class

- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
- **Authorized:** `roundf` from `<cmath>`.
- Add a constructor from `int` and a constructor from `float`.
- Add `toFloat() const` and `toInt() const`.
- Overload `operator<<` to print the fixed-point value as a float.
- The fractional part remains 8 bits.

Example:

```text
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
```

### ex02 - Now we're talking

- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
- **Authorized:** `roundf` from `<cmath>`.
- Overload the six comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`.
- Overload the four arithmetic operators: `+`, `-`, `*`, `/`.
- Overload pre/post increment and pre/post decrement. They must add or subtract the smallest representable epsilon.
- Add four static `min`/`max` overloads:
  - `min(Fixed&, Fixed&)`, `min(Fixed const&, Fixed const&)`;
  - `max(Fixed&, Fixed&)`, `max(Fixed const&, Fixed const&)`.
- Division by zero may crash the program; that is accepted.

Example:

```text
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

### ex03 - BSP

- **Directory:** `ex03/`
- **Files:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`, `Point.{h,hpp}`, `Point.cpp`, `bsp.cpp`
- **Authorized:** `roundf` from `<cmath>`.
- Implement `Point` in OCF with two `Fixed const` attributes `x` and `y`.
- Implement `bool bsp(Point const a, Point const b, Point const c, Point const point)`.
- Return `true` only when the point is strictly inside the triangle.
- A point on a vertex or on an edge returns `false`.
- BSP stands for Binary Space Partitioning, but the exercise only needs the point-in-triangle test.
- Completing this exercise is **not mandatory** to pass the module.

## Build and run

```bash
cd CPP_Module_02/ex00 && make && ./Fixed
cd CPP_Module_02/ex01 && make && ./Fixed
cd CPP_Module_02/ex02 && make && ./Fixed
cd CPP_Module_02/ex03 && make && ./Fixed
```

## Evaluation notes

- Every class must be in OCF, including `Point`.
- Copy operations must not share state incorrectly.
- `min`/`max` must have both const and non-const overloads.
- `toInt()` truncates toward zero.
- The insertion operator must be a non-member function.
- The 8 fractional bits must be a static constant, not a magic number repeated everywhere.
- STL containers and algorithms are forbidden.
