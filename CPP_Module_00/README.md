# CPP Module 00 - Namespaces, Classes, Member Functions and Stdio Streams

<img width="888" height="246" alt="CPP Module 00" src="https://github.com/user-attachments/assets/0c6b61c8-3cbd-4cf9-ba1c-57fab534eac6" />

- **Rank:** 04
- **Language:** C++98
- **Subject:** [subjects/cpp00.pdf](../subjects/cpp00.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 00 is the entry point of the CPP piscine. It assumes that you already know how to program in C and introduces the parts of C++ needed to write small, clean programs: namespaces, standard streams, `std::string`, classes, member functions, access control, initialization lists, `const`, `static` and output formatting.

The three exercises are deliberately small. The goal is not to build a large application; it is to stop writing C and start writing C++.

## Learning objectives

- Understand the structure of a C++ program.
- Use `std::cout` and `std::cin` instead of `printf` and `scanf`.
- Use `std::string` instead of C strings.
- Create classes with private attributes and public member functions.
- Use constructors and initialization lists.
- Use `const` and `static` correctly.
- Format output with `iomanip`.
- Manage a fixed-size collection without dynamic allocation.

## Key concepts

### Namespaces

The standard library lives in the `std` namespace. Writing `using namespace std;` is forbidden by the general rules, so every standard name must be qualified:

```cpp
std::cout << "Hello" << std::endl;
std::string name;
```

### Streams

`std::cout`, `std::cerr` and `std::cin` are type-safe and extensible. They replace `printf`, `fprintf` and `scanf`, which are forbidden.

### Classes and encapsulation

A class groups data and behaviour. Attributes are private by default in good designs; the public interface exposes only what users need. Member functions can be defined inside or outside the class body.

### Fixed-size storage

Exercise 01 explicitly forbids dynamic allocation. The phonebook stores its contacts in a fixed array and reuses slots when the ninth contact arrives.

## Exercises

### ex00 - Megaphone

- **Directory:** `ex00/`
- **Files:** `Makefile`, `megaphone.cpp`
- **Goal:** print every command-line argument in uppercase, concatenated without separators.
- **No arguments:** print `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.
- **Constraints:** use C++ streams; no `printf`.

Example:

```text
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### ex01 - My Awesome PhoneBook

- **Directory:** `ex01/`
- **Files:** `Makefile`, `*.cpp`, `*.{h,hpp}`
- **Classes:** `PhoneBook` and `Contact`.
- **Capacity:** 8 contacts. A ninth contact replaces the oldest one.
- **Dynamic allocation:** forbidden.
- **Commands:** `ADD`, `SEARCH`, `EXIT`. Any other input is ignored.

`ADD` asks for first name, last name, nickname, phone number and darkest secret, one field at a time. A contact with an empty field is rejected.

`SEARCH` displays the saved contacts as a table with four columns: index, first name, last name and nickname. Each column is 10 characters wide, right-aligned, separated by `|`. Text longer than 10 characters is truncated and its last visible character becomes a dot. The program then asks for an index and prints the selected contact one field per line.

`EXIT` quits and loses all contacts.

The exercise expects `iomanip` (`std::setw`, `std::right`) for the table.

This implementation links against `readline` and `ncurses` and provides a friendlier prompt. The Makefile contains the required `-lreadline -lncurses` flags.

### ex02 - The Job Of Your Dreams

- **Directory:** `ex02/`
- **Files:** `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp`
- **Goal:** recreate the missing `Account.cpp`.
- `Account.hpp`, `tests.cpp` and a reference log are provided by the subject.
- The output of `tests.cpp` must match the reference log, except for timestamps.
- The exercise practices static members, constructors, destructors, output formatting and deducing behaviour from a header plus a log.
- Completing this exercise is **not mandatory** to pass the module.

## Build and run

```bash
cd CPP_Module_00/ex00 && make && ./megaphone "hello"
cd CPP_Module_00/ex01 && make && ./phonebook
cd CPP_Module_00/ex02 && make && ./globalbanksters
```

All Makefiles use:

```make
CXX      = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
```

Use `make clean`, `make fclean` and `make re` to manage artifacts.

## Evaluation notes

- Do not use `printf`, `malloc` or `free`.
- Do not use STL containers or algorithms. They are allowed only in Modules 08 and 09.
- The phonebook must not allocate contacts dynamically.
- The phonebook table must respect the 10-character columns and the truncation rule.
- Empty contact fields must not be accepted.
- The `Account` output must match the log except for timestamps; destructor order may vary by compiler.
