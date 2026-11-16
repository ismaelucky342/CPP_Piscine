# CPP Module 09 - STL

- **Rank:** 05
- **Language:** C++98
- **Subject:** [subjects/cpp09.pdf](../subjects/cpp09.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 09 closes the CPP piscine with three programs that use the STL in realistic ways: a Bitcoin exchange calculator, a Reverse Polish Notation evaluator and a merge-insertion sort benchmark.

Each exercise forbids the container used in the previous one, which forces the student to choose a data structure based on the problem rather than on habit.

## Learning objectives

- Use `std::map` for ordered date lookup.
- Parse and validate CSV-like input.
- Use `std::stack` for expression evaluation.
- Handle errors with exceptions and explicit messages.
- Implement the Ford-Johnson merge-insertion sort.
- Compare the performance of `std::vector` and `std::deque`.
- Measure and display execution time.

## Key concepts

### Ordered lookup with `std::map`

`std::map` keeps its keys sorted. `lower_bound(date)` returns the first element whose key is not less than `date`. To find the closest lower date:

- if the key is equal, use it;
- otherwise, step back one element;
- if there is no lower element, the date is before the database and cannot be resolved.

### Input validation

Real input is hostile. Dates must be real calendar dates, values must be numeric, in range and not contain trailing garbage. Each invalid line produces a specific error message and does not stop the program.

### RPN evaluation

Reverse Polish Notation evaluates left to right with a stack:

- a number is pushed;
- an operator pops two operands, applies the operation and pushes the result.

At the end, exactly one value must remain.

### Ford-Johnson merge-insertion sort

Ford-Johnson is a comparison sort based on:

1. pairing elements and ordering each pair;
2. recursively sorting the larger elements of the pairs;
3. inserting the smaller elements in Jacobsthal order using binary insertion.

It minimizes the number of comparisons in the worst case. The executable must display the time taken by the algorithm for two different containers.

## Exercises

### ex00 - Bitcoin Exchange

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `BitcoinExchange.{cpp,hpp}`, `data.csv`
- **Program name:** `btc`.
- **Input:** a file passed as the only argument.
- **Line format:** `date | value`.
- **Valid date:** `YYYY-MM-DD`, including month and day ranges and leap years.
- **Valid value:** a float or a positive integer between 0 and 1000.
- **Output:** `date => value = result`, where `result` is the value multiplied by the exchange rate of the date.
- **Missing date:** use the closest **lower** date in the database.
- **Errors:**
  - `Error: could not open file.`
  - `Error: bad input => <line>`
  - `Error: not a positive number.`
  - `Error: too large a number.`
- At least one container must be used; this implementation uses `std::map`.
- The container used here cannot be reused in the next exercises.

Example:

```text
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

### ex01 - Reverse Polish Notation

- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `RPN.{cpp,hpp}`
- **Program name:** `RPN`.
- **Input:** an inverted Polish mathematical expression as the only argument.
- **Numbers:** always less than 10 in the input; the result is not limited.
- **Operators:** `+`, `-`, `*`, `/`.
- **Errors:** print an error on standard error and exit with a non-zero status.
- **Not required:** brackets and decimal numbers.
- At least one container must be used; this implementation uses `std::stack`.
- The container used here cannot be reused in the next exercise.

Examples:

```text
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
```

Edge cases to handle:

- division by zero;
- too few operands for an operator;
- more than one value left on the stack at the end;
- unknown characters.

### ex02 - PmergeMe

- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`, `PmergeMe.{cpp,hpp}`
- **Program name:** `PmergeMe`.
- **Input:** a sequence of positive integers as arguments.
- **Algorithm:** merge-insertion sort, also known as Ford-Johnson.
- **Containers:** at least two different containers; this implementation uses `std::vector` and `std::deque`.
- **Capacity:** at least 3000 different integers.
- **Errors:** negative numbers, non-numeric arguments and duplicates are rejected on standard error.
- **Output:**
  - `Before: <unsorted sequence>`
  - `After: <sorted sequence>`
  - time for the first container, in microseconds;
  - time for the second container, in microseconds.

Example:

```text
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque : 0.00014 us
```

The timing format is free, but the precision must clearly show the difference between the two containers.

## Build and run

```bash
cd CPP_Module_09/ex00 && make && ./btc input.txt
cd CPP_Module_09/ex01 && make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
cd CPP_Module_09/ex02 && make && ./PmergeMe 3 5 9 7 4
```

Large PmergeMe test:

```bash
cd CPP_Module_09/ex02
./PmergeMe $(seq 1 3000 | shuf)
```

## Evaluation notes

- Each exercise must use a different container from the previous one where the subject requires it.
- `btc` must validate dates and numeric values, not just parse them.
- `btc` must use the closest lower date, never a higher one.
- `RPN` must handle malformed expressions and division by zero.
- `PmergeMe` must implement Ford-Johnson, use two containers and handle at least 3000 integers.
- `PmergeMe` must not lose elements; the output length must equal the input length.
- Timings must be in microseconds and clearly distinguish the two containers.
- No leaks.
