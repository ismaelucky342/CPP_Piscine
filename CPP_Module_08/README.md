# CPP Module 08 - Templated Containers, Iterators and Algorithms

- **Rank:** 05
- **Language:** C++98
- **Subject:** [subjects/cpp08.pdf](../subjects/cpp08.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 08 is the first module where the STL is allowed. It covers generic functions, containers, iterators and algorithms. The three exercises move from a simple generic search to a performance-sensitive container and finally to making `std::stack` iterable.

The module is where the student starts using the standard library instead of reimplementing everything by hand.

## Learning objectives

- Write a function template that works with several STL containers.
- Use `std::find` and iterator ranges.
- Use `std::vector`, `std::list` and `std::deque`.
- Sort values and compute spans efficiently.
- Fill a container from an iterator range.
- Inherit from an STL container and expose its underlying container's iterators.
- Use `std::lower_bound`/`std::sort` and understand their complexity.

## Key concepts

### Containers and iterators

An STL container exposes `begin()` and `end()`. Algorithms operate on iterator ranges, not on containers directly. This separation is what makes the STL generic.

### Algorithms

`std::find` returns an iterator to the first matching element or `end()`. `std::sort` sorts a range in place. `std::lower_bound` finds the first position where a value could be inserted without breaking the order.

### Complexity

`Span::shortestSpan()` must not compare every pair of values: that would be O(n^2). Sorting the values first and comparing adjacent elements is O(n log n) and is the expected solution.

### Adapting a container

`std::stack` is a container adaptor with a protected member `c` that holds the underlying container. A derived class can expose `c.begin()` and `c.end()` as its own iterators.

## Exercises

### ex00 - Easy find

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `easyfind.{h,hpp}`, optional `easyfind.tpp`
- **Function template:**

```cpp
template <typename T>
int easyfind(T& container, int target);
```

- `T` is a container of integers.
- Find the first occurrence of `target`.
- If no occurrence is found, throw an exception or return an error value. The implementation in this repository throws `std::invalid_argument`.
- It must work with at least `std::vector`, `std::list` and `std::deque`.
- Associative containers do not have to be supported.
- The main must contain tests for a found value, a missing value and an empty container.

### ex01 - Span

- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `Span.{h,hpp}`, `Span.cpp`
- `Span(unsigned int N)` stores at most N integers.
- `addNumber(int)` adds one number and throws if the span is full.
- `shortestSpan()` returns the smallest difference between any two stored numbers.
- `longestSpan()` returns the difference between the largest and the smallest stored number.
- Both throw when there are fewer than two numbers.
- Add a range-filling member function, for example:

```cpp
template <typename InputIterator>
void addRange(InputIterator begin, InputIterator end);
```

- Test with at least 10,000 numbers; more is better.
- Reference output for `6, 3, 17, 9, 11`:

```text
2
14
```

- The shortest span must be computed in O(n log n), not O(n^2).

### ex02 - Mutated abomination

- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`, `MutantStack.{h,hpp}`, optional `MutantStack.tpp`
- `std::stack` is not iterable.
- Implement `MutantStack<T>`, in terms of `std::stack`, offering all stack members plus:
  - `iterator begin()`;
  - `iterator end()`;
  - const versions of both.
- The test from the subject pushes `5, 17, 3, 5, 737, 0`, pops once, then iterates. Running the same test with `std::list` must produce the same output.

Example:

```text
5
3
5
737
0
```

## Build and run

```bash
cd CPP_Module_08/ex00 && make && ./easyfind
cd CPP_Module_08/ex01 && make && ./span
cd CPP_Module_08/ex02 && make && ./mutantStack
```

`ex01` writes a `logs` file during its test; it is ignored by git.

## Evaluation notes

- `easyfind` must work with several container types, not only `std::vector`.
- `Span` must not use an O(n^2) shortest-span algorithm.
- `Span::addNumber` must throw when the span is full.
- `shortestSpan` and `longestSpan` must throw when there are fewer than two values.
- `MutantStack` must expose real iterators over the underlying container.
- No leaks.
- This is the first module where STL containers and algorithms are allowed; using them here is expected.
