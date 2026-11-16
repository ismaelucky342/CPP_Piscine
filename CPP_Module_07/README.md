# CPP Module 07 - C++ Templates

- **Rank:** 05
- **Language:** C++98
- **Subject:** [subjects/cpp07.pdf](../subjects/cpp07.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 07 introduces generic programming with templates. The first exercise is a set of function templates, the second applies a function to an array, and the third implements a small dynamic array class template.

The recurring constraint is that template definitions must be visible at the point of instantiation, so they live in headers or in `.tpp` files included by headers.

## Learning objectives

- Write function templates.
- Write class templates.
- Understand template instantiation and header-only definitions.
- Support both `const` and non-const types.
- Use `new[]` and `delete[]` in a template class.
- Throw exceptions from a template member function.
- Respect the Orthodox Canonical Form in a template class.

## Key concepts

### Function templates

A function template is a recipe for a family of functions:

```cpp
template <typename T>
void swap(T& a, T& b);
```

The compiler instantiates the correct version when the function is called. The arguments must support the operations used in the body.

### Class templates

A class template parameterizes a class:

```cpp
template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;
public:
    Array();
    Array(unsigned int n);
    Array(Array const& other);
    Array& operator=(Array const& other);
    ~Array();
    T& operator[](unsigned int index);
    unsigned int size() const;
};
```

The implementation usually goes in the header, often in a `.tpp` file included at the end.

### Const correctness

`iter()` must work with both `T*` and `T const*`, and the callable must accept either `T&` or `T const&`. Template argument deduction and overload resolution do the work if the signature is written carefully.

### Memory management in templates

`Array<T>` owns a heap array. The copy constructor and copy assignment operator must allocate a new array and copy every element. The destructor must use `delete[]`. Bounds checking in `operator[]` throws an exception.

## Exercises

### ex00 - Start with a few functions

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `whatever.{h,hpp}`
- Implement three function templates:
  - `swap(T& a, T& b)`: swaps the two values, returns nothing;
  - `min(T const& a, T const& b)`: returns the smaller value; if equal, returns `b`;
  - `max(T const& a, T const& b)`: returns the greater value; if equal, returns `b`.
- The two arguments must have the same type and support the comparison operators.
- The templates must be defined in the header.
- The subject's test must produce:

```text
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
```

### ex01 - Iter

- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `iter.{h,hpp}`
- Implement:

```cpp
template <typename T>
void iter(T* array, size_t length, void (*f)(T&));
```

- The function applies `f` to every element of the array.
- It must work with any array type.
- The function passed as the third parameter may be an instantiated function template.
- It must support both const and non-const elements.
- The main must contain enough tests to prove it works.

### ex02 - Array

- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`, `Array.{h,hpp}`, optional `Array.tpp`
- Implement `Array<T>`:
  - default constructor creates an empty array;
  - constructor with `unsigned int n` creates `n` default-initialized elements;
  - copy constructor and copy assignment produce independent copies;
  - `operator[]` throws a `std::exception` when the index is out of bounds;
  - `size() const` returns the number of elements.
- Memory must be allocated with `new[]`; preventive allocation is forbidden.
- Never access non-allocated memory.
- The class must be in Orthodox Canonical Form.

## Build and run

```bash
cd CPP_Module_07/ex00 && make && ./ex00
cd CPP_Module_07/ex01 && make && ./iter
cd CPP_Module_07/ex02 && make && ./array
```

## Evaluation notes

- Template definitions must be in headers or `.tpp` files included by headers.
- Do not implement non-template functions in headers.
- `min` and `max` must return the second argument when the values are equal.
- `iter` must handle const and non-const arrays.
- `Array<T>` must deep-copy and must not leak.
- Out-of-bounds access must throw.
- STL containers and algorithms are forbidden.
- The Makefile in `ex01` builds a binary named `iter`; an older version incorrectly reused the name `ex00`.
