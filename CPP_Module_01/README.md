# CPP Module 01 - Memory Allocation, Pointers, References and File I/O

<img width="921" height="223" alt="CPP Module 01" src="https://github.com/user-attachments/assets/67e0755f-5526-4f28-b8a7-e8055dba7155" />

- **Rank:** 04
- **Language:** C++98
- **Subject:** [subjects/cpp01.pdf](../subjects/cpp01.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 01 is about object lifetime and about the difference between pointers and references. It also introduces member-function pointers, C++ file streams and the `switch` statement. Seven exercises build a small toolkit that will be reused in later modules.

## Learning objectives

- Choose between stack and heap allocation.
- Allocate and release objects correctly with `new` and `delete`/`delete[]`.
- Understand pointers versus references.
- Use references as class members and function parameters.
- Use pointers to member functions instead of long `if`/`else` chains.
- Read and write files with `std::ifstream` and `std::ofstream`.
- Use `switch` with explicit control flow.

## Key concepts

### Stack versus heap

Stack objects are destroyed automatically at the end of their scope. Heap objects live until they are explicitly deleted. A function that returns a pointer to a local object is a bug; a function that returns a heap object transfers ownership to the caller.

### Pointers versus references

- A pointer can be null, can be reassigned and needs dereferencing.
- A reference cannot be null, cannot be reseated and behaves like an alias.
- A class that must always have a valid object can store a reference; a class that may not have one must store a pointer.

### Member-function pointers

An array of `{level, &Harl::function}` pairs lets `complain()` dispatch without a long conditional chain.

### File streams

`std::ifstream` and `std::ofstream` are the C++ replacements for `FILE*` and the C file functions, which are forbidden in this module.

## Exercises

### ex00 - BraiiiiiiinnnzzzZ

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`
- `Zombie` has a private `name` and `announce()` printing `<name>: BraiiiiiiinnnzzzZ...`.
- `newZombie(std::string name)` allocates a zombie with `new`, names it and returns it so it can be used outside the function scope.
- `randomChump(std::string name)` creates a zombie on the stack, makes it announce itself and lets it die at the end of the function.
- The destructor prints a debug message containing the zombie name.
- The exercise asks you to justify when stack allocation is enough and when heap allocation is needed.

### ex01 - Moar brainz!

- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `zombieHorde.cpp`
- `Zombie* zombieHorde(int N, std::string name)` allocates N zombies in a **single allocation** and initializes all of them with the same name.
- It returns a pointer to the first zombie.
- The caller frees the horde with `delete[]`.
- Test it by calling `announce()` on every zombie and checking for leaks.

### ex02 - HI THIS IS BRAIN

- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`
- Create a string initialized to `"HI THIS IS BRAIN"`.
- Create `stringPTR`, a pointer to the string, and `stringREF`, a reference to the string.
- Print the address of the variable, the address held by the pointer and the address held by the reference.
- Print the value of the variable, the value pointed to by the pointer and the value referred to by the reference.
- The goal is to show that a reference is another name for the same object.

### ex03 - Unnecessary violence

- **Directory:** `ex03/`
- **Files:** `Makefile`, `main.cpp`, `Weapon.{h,hpp}`, `Weapon.cpp`, `HumanA.{h,hpp}`, `HumanA.cpp`, `HumanB.{h,hpp}`, `HumanB.cpp`
- `Weapon` has a private `std::string type`, `getType()` returning a constant reference and `setType()`.
- `HumanA` always has a weapon and receives it in its constructor. It stores a reference to `Weapon`.
- `HumanB` may not have a weapon and receives it later through `setWeapon()`. It stores a pointer to `Weapon`.
- Both print `<name> attacks with their <weapon type>`.
- The exercise is about choosing a reference when the object is guaranteed and a pointer when it is optional.

Expected output of the reference test:

```text
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club
```

### ex04 - Sed is for losers

- **Directory:** `ex04/`
- **Files:** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`
- The program takes three parameters: a filename, `s1` and `s2`.
- It copies the file to `<filename>.replace`, replacing every occurrence of `s1` with `s2`.
- `std::string::replace` is forbidden.
- C file-manipulation functions are forbidden.
- All other `std::string` member functions are allowed.
- Handle missing files, empty strings and invalid arguments.

### ex05 - Harl 2.0

- **Directory:** `ex05/`
- **Files:** `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`
- `Harl` has private `debug()`, `info()`, `warning()` and `error()` member functions.
- `complain(std::string level)` calls the matching function through an array of pointers to member functions.
- A forest of `if`/`else if`/`else` is not accepted.

### ex06 - Harl filter

- **Directory:** `ex06/`
- **Files:** `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`
- The program takes one of the four levels as an argument and prints every message from that level and above.
- `WARNING` prints `WARNING` and `ERROR`; `DEBUG` prints all four levels.
- An unknown level prints `[ Probably complaining about insignificant problems ]`.
- The subject explicitly asks for a `switch` statement.
- Completing this exercise is **not mandatory** to pass the module.

## Build and run

```bash
cd CPP_Module_01/ex00 && make && ./Zombie
cd CPP_Module_01/ex02 && make && ./brain
cd CPP_Module_01/ex04 && make && ./program file.txt old new
cd CPP_Module_01/ex06 && make && ./violence WARNING
```

## Evaluation notes

- No leaks: every `new` must have a matching `delete`, every `new[]` a matching `delete[]`.
- Do not return pointers or references to local variables.
- `HumanA` must use a reference and `HumanB` a pointer; the evaluator will ask why.
- `ex04` must not use `std::string::replace` or C file functions.
- `ex05` and `ex06` must use member-function pointers and `switch` respectively.
- STL containers and algorithms are forbidden in this module.
