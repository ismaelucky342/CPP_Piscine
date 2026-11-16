# CPP Module 03 - Inheritance

<img width="920" height="226" alt="CPP Module 03" src="https://github.com/user-attachments/assets/93997871-a73a-4303-bae6-47abc5acdcd5" />

- **Rank:** 04
- **Language:** C++98
- **Subject:** [subjects/cpp03.pdf](../subjects/cpp03.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 03 introduces inheritance through a family of robots derived from `ClapTrap`. It covers construction and destruction order, method overriding, protected attributes, multiple inheritance and the diamond problem.

The module is intentionally repetitive: `ScavTrap` and `FragTrap` are almost identical, and `DiamondTrap` combines both. The repetition makes the construction chain and the ambiguity of multiple inheritance visible.

## Learning objectives

- Derive classes publicly from a base class.
- Understand the order of construction and destruction.
- Reuse base-class attributes while keeping them `protected` when needed.
- Override member functions.
- Understand non-virtual versus virtual inheritance.
- Solve the diamond problem with virtual inheritance.
- Handle name shadowing between a base class and a derived class.

## Key concepts

### Construction and destruction order

When a derived object is created:

1. the base subobject is constructed first;
2. then the derived part is constructed.

Destruction happens in reverse order. The tests must show this explicitly.

### Inheritance and access

- `public` inheritance models an "is-a" relationship.
- `protected` attributes are accessible to derived classes but not to the outside world.
- A derived class can call base-class member functions and access protected attributes.

### Diamond problem

If `DiamondTrap` inherits from both `FragTrap` and `ScavTrap`, and both inherit from `ClapTrap`, a naive design creates two `ClapTrap` subobjects. Virtual inheritance makes `FragTrap` and `ScavTrap` share a single `ClapTrap` subobject:

```cpp
class FragTrap : virtual public ClapTrap { ... };
class ScavTrap : virtual public ClapTrap { ... };
class DiamondTrap : public FragTrap, public ScavTrap { ... };
```

The most-derived class is responsible for initializing the virtual base.

### Name shadowing

`DiamondTrap` declares its own `name` attribute with exactly the same name as the one in `ClapTrap`. This is deliberate: it forces the student to understand scope resolution (`DiamondTrap::name` versus `ClapTrap::name`) and the `-Wshadow` warning.

## Exercises

### ex00 - Aaaaand... OPEN!

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `ClapTrap.{h,hpp}`, `ClapTrap.cpp`
- **Attributes:** name (constructor parameter), 10 hit points, 10 energy points, 0 attack damage.
- **Member functions:**
  - `attack(std::string const& target)`;
  - `takeDamage(unsigned int amount)`;
  - `beRepaired(unsigned int amount)`.
- Attacking and repairing each cost 1 energy point.
- A ClapTrap with 0 hit points or 0 energy points cannot act.
- Every action and every constructor/destructor prints a message.
- The robots do not interact directly with each other in this exercise.

Example message:

```text
ClapTrap <name> attacks <target>, causing <damage> points of damage!
```

### ex01 - Serena, my love!

- **Directory:** `ex01/`
- **Files:** previous files plus `ScavTrap.{h,hpp}`, `ScavTrap.cpp`
- `ScavTrap` inherits publicly from `ClapTrap`.
- Values: 100 hit points, 50 energy points, 20 attack damage.
- Its constructors, destructor and `attack()` print different messages.
- `guardGate()` prints that the ScavTrap is in Gate keeper mode.
- The tests must show the `ClapTrap` construction/destruction chain.

### ex02 - Repetitive work

- **Directory:** `ex02/`
- **Files:** previous files plus `FragTrap.{h,hpp}`, `FragTrap.cpp`
- `FragTrap` inherits publicly from `ClapTrap`.
- Values: 100 hit points, 100 energy points, 30 attack damage.
- Its constructor, destructor and messages differ from `ScavTrap`.
- `highFivesGuys()` prints a positive high-five request.
- The tests must show the construction/destruction chain.

### ex03 - Now it's weird!

- **Directory:** `ex03/`
- **Files:** previous files plus `DiamondTrap.{h,hpp}`, `DiamondTrap.cpp`
- `DiamondTrap` inherits from both `FragTrap` and `ScavTrap`.
- It has a private `name` attribute with exactly the same variable name as in `ClapTrap`.
- Its `ClapTrap` name is the robot name plus `_clap_name`.
- Hit points come from `FragTrap` (100), energy points from `ScavTrap` (50), attack damage from `FragTrap` (30).
- `attack()` comes from `ScavTrap`.
- `whoAmI()` prints both the `DiamondTrap` name and the `ClapTrap` name.
- The `ClapTrap` subobject must be constructed once and only once: use virtual inheritance.
- Completing this exercise is **not mandatory** to pass the module.
- The subject suggests experimenting with `-Wshadow` and `-Wno-shadow`.

## Build and run

```bash
cd CPP_Module_03/ex00 && make && ./ScavTrap
cd CPP_Module_03/ex01 && make && ./scavtrap
cd CPP_Module_03/ex02 && make && ./scavtrap
cd CPP_Module_03/ex03 && make && ./scavtrap
```

## Evaluation notes

- Construction and destruction order must be visible in the output.
- Each class must print its own messages; do not reuse the same string for every class.
- `DiamondTrap` must not construct two `ClapTrap` subobjects.
- Copy constructors must explicitly initialize their base classes. This repository fixes the missing base initialization in `ScavTrap`, `FragTrap` and `DiamondTrap`.
- `DiamondTrap::whoAmI()` must show both names.
- STL containers and algorithms are forbidden.
