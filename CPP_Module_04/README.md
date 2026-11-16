# CPP Module 04 - Subtype Polymorphism, Abstract Classes and Interfaces

<img width="1657" height="308" alt="CPP Module 04" src="https://github.com/user-attachments/assets/6323727b-2f13-4c59-93b6-048b88d550a1" />

- **Rank:** 04
- **Language:** C++98
- **Subject:** [subjects/cpp04.pdf](../subjects/cpp04.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 04 is the culmination of the object-oriented half of the CPP piscine. It turns inheritance into **subtype polymorphism**: virtual functions, virtual destructors, abstract classes, deep copies and pure abstract classes used as interfaces.

The module builds an animal hierarchy, then a materia/inventory system that looks like a small game subsystem. It is also the first module where memory ownership across inheritance hierarchies becomes critical.

## Learning objectives

- Understand virtual functions and runtime dispatch.
- Use virtual destructors correctly.
- Create abstract classes with pure virtual functions.
- Implement deep copies when a class owns resources.
- Avoid leaks when deleting derived objects through base pointers.
- Use pure abstract classes as interfaces.
- Design a small inventory system with ownership rules.
- Apply the Interface Segregation Principle in C++98.

## Key concepts

### Virtual functions

A virtual function is resolved at runtime based on the dynamic type of the object:

```cpp
Animal* a = new Dog();
a->makeSound(); // Dog::makeSound
```

Without `virtual`, the call is resolved statically and `Animal::makeSound` runs instead. `WrongAnimal`/`WrongCat` demonstrates this trap.

### Virtual destructors

Deleting a derived object through a base pointer without a virtual destructor is undefined behaviour and leaks the derived resources. `Animal` must have:

```cpp
virtual ~Animal();
```

### Abstract classes

A class with at least one pure virtual function cannot be instantiated:

```cpp
virtual void makeSound() const = 0;
```

It defines a contract that derived classes must fulfil. Such a class is commonly called an interface when it has no data and only pure virtual functions.

### Deep copy

If a class owns a `Brain*`, the copy constructor and copy assignment operator must allocate a new `Brain` and copy its contents. Copying the pointer would share the brain and cause a double delete.

### Ownership in the materia system

- `Character` owns the materias in its inventory and deletes them in its destructor.
- `unequip()` removes a materia without deleting it; the caller becomes responsible for it.
- `MateriaSource` learns copies of materias and deletes them when destroyed.
- `createMateria()` returns a new materia owned by the caller.

## Exercises

### ex00 - Polymorphism

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`
- **Classes:** `Animal`, `Dog`, `Cat`, `WrongAnimal`, `WrongCat`.
- `Animal` has a protected `std::string type`.
- `Dog` sets `type` to `"Dog"`, `Cat` sets it to `"Cat"`.
- `makeSound()` is virtual and prints the correct sound.
- `WrongAnimal`/`WrongCat` show what happens when `makeSound()` is not virtual.
- Every constructor and destructor prints a specific message.

Expected behaviour: the `Dog` and `Cat` pointers print their own sounds; the `Animal` pointer prints the generic sound. With the wrong hierarchy, `WrongCat` prints the `WrongAnimal` sound.

### ex01 - I don't want to set the world on fire

- **Directory:** `ex01/`
- **Files:** previous files plus `Brain.{h,hpp}`, `Brain.cpp`
- `Brain` contains an array of 100 `std::string` ideas.
- `Dog` and `Cat` have a private `Brain*` created with `new Brain()` and deleted in their destructor.
- `Animal` needs a virtual destructor so that `delete animalPtr` calls the derived destructor.
- Copy constructor and copy assignment of `Dog` and `Cat` must deep-copy the brain.
- Test an array of `Animal*` with half dogs and half cats, then delete every element as `Animal*`.
- No leaks: run the test under valgrind if possible.

### ex02 - Abstract class

- **Directory:** `ex02/`
- **Files:** previous files
- Give `Animal::makeSound()` a pure virtual declaration (`= 0`).
- `Animal` can no longer be instantiated.
- Everything else keeps working.
- The class may be renamed `AAnimal`.

### ex03 - Interface & recap

- **Directory:** `ex03/`
- **Files:** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`
- Complete `AMateria`:
  - protected `std::string type`;
  - `AMateria(std::string const& type)`;
  - `std::string const& getType() const`;
  - `virtual AMateria* clone() const = 0`;
  - `virtual void use(ICharacter& target)`.
- Implement `Ice` and `Cure`:
  - types `"ice"` and `"cure"`;
  - `clone()` returns a new instance of the same type;
  - `Ice::use()` prints `* shoots an ice bolt at <name> *`;
  - `Cure::use()` prints `* heals <name>'s wounds *`.
- Implement `ICharacter` and `Character`:
  - `getName()`;
  - `equip(AMateria*)`;
  - `unequip(int idx)`;
  - `use(int idx, ICharacter& target)`;
  - 4 inventory slots, filled from slot 0 to slot 3;
  - full inventory or invalid index: do nothing, but do not crash;
  - `unequip()` must not delete the materia;
  - copies of `Character` must be deep;
  - the destructor deletes the materias it owns.
- Implement `IMateriaSource` and `MateriaSource`:
  - `learnMateria(AMateria*)` stores a copy of the materia, up to 4;
  - `createMateria(std::string const& type)` returns a new materia of that type, or `0` if unknown.
- The subject's test should print:

```text
* shoots an ice bolt at bob *
* heals bob's wounds *
```

- Completing this exercise is **not mandatory** to pass the module.

## Build and run

```bash
cd CPP_Module_04/ex00 && make && ./Polymorphism
cd CPP_Module_04/ex01 && make && ./Polymorphism
cd CPP_Module_04/ex02 && make && ./Polymorphism
cd CPP_Module_04/ex03 && make && ./Polymorphism
```

A leak check is strongly recommended for `ex01` and `ex03`:

```bash
valgrind --leak-check=full ./Polymorphism
```

## Evaluation notes

- `Animal` must have a virtual destructor.
- `makeSound()` must be virtual in `ex00` and pure virtual in `ex02`.
- Deep copies must not share `Brain` or materias.
- If `unequip()` does not delete a materia, the test must free it later.
- `MateriaSource::createMateria()` must return `0` for an unknown type.
- No leaks in any exercise.
- STL containers and algorithms are forbidden.
