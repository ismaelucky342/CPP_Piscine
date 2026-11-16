# CPP Piscine - 42 Common Core

A consolidated repository for the ten C++ modules of the 42 Common Core: **CPP Module 00** through **CPP Module 09**.

Previously each module lived in its own GitHub repository. This repository brings all of them together, includes the official subjects, normalizes the build system and documents every module and every exercise.

- Language: **C++98**
- Compiler: **c++**
- Flags: **-Wall -Wextra -Werror**, and the code must still compile with **-std=c++98**
- Subjects: [`subjects/`](subjects/)

---

## Table of contents

1. [What this repository is](#what-this-repository-is)
2. [Where the CPP piscine sits in the cursus](#where-the-cpp-piscine-sits-in-the-cursus)
3. [General rules of the modules](#general-rules-of-the-modules)
4. [Modules at a glance](#modules-at-a-glance)
5. [Module 00 - Namespaces, classes, member functions, stdio streams](#module-00---namespaces-classes-member-functions-stdio-streams)
6. [Module 01 - Memory allocation, pointers, references and switch](#module-01---memory-allocation-pointers-references-and-switch)
7. [Module 02 - Ad-hoc polymorphism, operator overloading and OCF](#module-02---ad-hoc-polymorphism-operator-overloading-and-ocf)
8. [Module 03 - Inheritance](#module-03---inheritance)
9. [Module 04 - Subtype polymorphism, abstract classes and interfaces](#module-04---subtype-polymorphism-abstract-classes-and-interfaces)
10. [Module 05 - Repetition and exceptions](#module-05---repetition-and-exceptions)
11. [Module 06 - C++ casts](#module-06---c-casts)
12. [Module 07 - C++ templates](#module-07---c-templates)
13. [Module 08 - Templated containers, iterators, algorithms](#module-08---templated-containers-iterators-algorithms)
14. [Module 09 - STL](#module-09---stl)
15. [Build and run](#build-and-run)
16. [Repository layout](#repository-layout)
17. [Peer-evaluation checklist](#peer-evaluation-checklist)
18. [Credits](#credits)

---

## What this repository is

The CPP piscine is the C++ branch of the 42 Common Core. It is not a single project: it is a sequence of ten modules, each one made of several exercises. The modules are designed to be completed in order because every module reuses ideas and code from the previous ones.

The progression is deliberate:

- Modules **00 to 04** introduce object-oriented programming in C++98: classes, encapsulation, constructors/destructors, the Orthodox Canonical Form, references, inheritance, virtual functions, abstract classes and interfaces.
- Modules **05 to 09** move to advanced language features and the standard library: exceptions, casts, templates, STL containers, iterators and algorithms.

Each module has its own `README.md` with a detailed explanation of its exercises, expected behaviour and build instructions.

---

## Where the CPP piscine sits in the cursus

The 42 Common Core is organized in ranks. The CPP modules are split across two of them:

| Rank | Modules | Focus |
| --- | --- | --- |
| **Rank 04** | CPP 00, 01, 02, 03, 04 | C++ basics and object-oriented programming |
| **Rank 05** | CPP 05, 06, 07, 08, 09 | Exceptions, casts, templates and STL |

This split is visible in the `42Born2code` repository layout, where modules 00-04 are stored under `Rank 04/` and modules 05-09 under `Rank 05/`. The exact rank labels can change between 42 campuses and cursus revisions, but the pedagogical split is stable: first the object model, then the advanced language and library features.

### Rank 04 - from C to C++ and the object model

Rank 04 is where the student stops writing C with a `.cpp` extension and starts thinking in C++:

- namespaces and stream I/O;
- classes, access control and member functions;
- initialization lists and `const`;
- stack versus heap allocation;
- pointers versus references;
- the Orthodox Canonical Form;
- operator overloading;
- inheritance, construction/destruction order and virtual dispatch;
- abstract classes and interfaces;
- manual memory management without leaks.

### Rank 05 - advanced C++ and the STL

Rank 05 assumes that the object model is understood and adds the parts of C++ that make large programs practical:

- exception safety and custom exception classes;
- C++ casts (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`);
- function and class templates;
- template specialization and template constraints by usage;
- STL containers, iterators and algorithms;
- algorithmic complexity and measured performance.

The two halves can be summarized as: **Rank 04 teaches you how to design C++ objects; Rank 05 teaches you how to use the C++ language and library at scale.**

---

## General rules of the modules

These rules are common to the ten modules and are taken from the subjects:

- Compile with `c++` and `-Wall -Wextra -Werror`.
- The code must still compile when `-std=c++98` is added.
- No external library. C++11 and later, Boost and any third-party library are forbidden.
- The following C functions are forbidden: `*printf()`, `*alloc()` and `free()`.
- `using namespace <ns_name>` and the `friend` keyword are forbidden unless the subject explicitly allows them.
- **STL containers and algorithms are allowed only in Modules 08 and 09.** Until then, do not include `<vector>`, `<list>`, `<map>`, `<algorithm>`, etc.
- From Module 02 onward, every class must be in Orthodox Canonical Form unless the subject says otherwise.
- A non-template function implemented in a header is forbidden.
- Headers must be independent and protected by include guards.
- Every allocation with `new` must be matched by `delete`/`delete[]`; no leaks.
- Output messages must end with a newline unless specified otherwise.
- Exercise directories are named `ex00`, `ex01`, and so on.

The full text of each subject is in [`subjects/`](subjects/).

---

## Modules at a glance

| Module | Rank | Theme | Exercises | Main concepts |
| --- | --- | --- | --- | --- |
| [00](#module-00---namespaces-classes-member-functions-stdio-streams) | 04 | Namespaces, classes, member functions, stdio streams | 3 | classes, streams, `const`, `static`, `iomanip` |
| [01](#module-01---memory-allocation-pointers-references-and-switch) | 04 | Memory allocation, pointers, references, switch | 7 | stack/heap, `new`/`delete`, references, member-function pointers, file I/O |
| [02](#module-02---ad-hoc-polymorphism-operator-overloading-and-ocf) | 04 | Ad-hoc polymorphism, operator overloading, OCF | 4 | Orthodox Canonical Form, fixed-point numbers, operator overloading |
| [03](#module-03---inheritance) | 04 | Inheritance | 4 | construction/destruction chaining, virtual inheritance, shadowing |
| [04](#module-04---subtype-polymorphism-abstract-classes-and-interfaces) | 04 | Subtype polymorphism, abstract classes, interfaces | 4 | virtual functions, abstract classes, deep copy, interfaces |
| [05](#module-05---repetition-and-exceptions) | 05 | Repetition and exceptions | 4 | exceptions, abstract forms, polymorphism, factory-like creation |
| [06](#module-06---c-casts) | 05 | C++ casts | 3 | scalar conversion, `uintptr_t`, `static_cast`, `dynamic_cast`, `reinterpret_cast` |
| [07](#module-07---c-templates) | 05 | C++ templates | 3 | function templates, class templates, template headers |
| [08](#module-08---templated-containers-iterators-algorithms) | 05 | Templated containers, iterators, algorithms | 3 | STL containers, algorithms, iterators, generic programming |
| [09](#module-09---stl) | 05 | STL | 3 | maps, stacks, containers, Ford-Johnson merge-insertion sort |

---

## Module 00 - Namespaces, classes, member functions, stdio streams

Rank: **04**  
Subject: [`subjects/cpp00.pdf`](subjects/cpp00.pdf)  
Module README: [`CPP_Module_00/README.md`](CPP_Module_00/README.md)

This module is the bridge between C and C++. It introduces the minimum amount of C++ needed to write small programs: namespaces, `std::cout`/`std::cin`, `std::string`, classes, member functions, initialization lists, `const`, `static` and output formatting.

### ex00 - Megaphone

- Directory: `ex00/`
- Files: `Makefile`, `megaphone.cpp`
- The program prints its command-line arguments in uppercase.
- With no arguments it prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.
- The point is to use C++ streams instead of `printf`.

### ex01 - My Awesome PhoneBook

- Directory: `ex01/`
- Files: `Makefile`, `*.cpp`, `*.{h,hpp}`
- Two classes: `PhoneBook` and `Contact`.
- The phonebook stores at most 8 contacts; adding a ninth replaces the oldest one.
- Dynamic allocation is forbidden.
- Commands: `ADD`, `SEARCH`, `EXIT`. Any other input is ignored.
- `ADD` asks for first name, last name, nickname, phone number and darkest secret. Empty fields are rejected.
- `SEARCH` lists contacts in four 10-character columns separated by `|`, right-aligned, truncating long values with a dot. Then it asks for an index and prints the full contact.
- `iomanip` is expected for the formatting.
- The executable should have a meaningful name (`phonebook` in this repository).

### ex02 - The Job Of Your Dreams

- Directory: `ex02/`
- Files: `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp`
- `Account.hpp`, `tests.cpp` and a log file are provided by the subject.
- The task is to recreate the missing `Account.cpp` so that the output of `tests.cpp` matches the reference log, ignoring timestamps.
- This exercise practices static members, constructors/destructors, output formatting and reverse-engineering behaviour from a header and a log.
- Completing this exercise is not mandatory to pass the module.

---

## Module 01 - Memory allocation, pointers, references and switch

Rank: **04**  
Subject: [`subjects/cpp01.pdf`](subjects/cpp01.pdf)  
Module README: [`CPP_Module_01/README.md`](CPP_Module_01/README.md)

This module focuses on object lifetime and on the difference between pointers and references. It also introduces member-function pointers, file streams and the `switch` statement.

### ex00 - BraiiiiiiinnnzzzZ

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`
- `Zombie` has a private `name` and an `announce()` function printing `<name>: BraiiiiiiinnnzzzZ...`.
- `newZombie(name)` allocates a zombie on the heap and returns it.
- `randomChump(name)` creates a zombie on the stack, makes it announce itself and lets it die.
- The destructor prints a debug message.
- The point is to decide when stack allocation is enough and when heap allocation is necessary.

### ex01 - Moar brainz!

- Directory: `ex01/`
- Files: `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `zombieHorde.cpp`
- `zombieHorde(int N, std::string name)` allocates N zombies in a single allocation and initializes all of them with the same name.
- It returns a pointer to the first zombie.
- The horde must be freed with `delete[]`.

### ex02 - HI THIS IS BRAIN

- Directory: `ex02/`
- Files: `Makefile`, `main.cpp`
- Create a string, a pointer to it and a reference to it.
- Print the address of the variable, the address held by the pointer and the address held by the reference.
- Then print the value through the variable, the pointer and the reference.
- The goal is to demystify references: they are another syntax for address manipulation.

### ex03 - Unnecessary violence

- Directory: `ex03/`
- Files: `Makefile`, `main.cpp`, `Weapon.{h,hpp}`, `Weapon.cpp`, `HumanA.{h,hpp}`, `HumanA.cpp`, `HumanB.{h,hpp}`, `HumanB.cpp`
- `Weapon` has a private `type`, `getType()` and `setType()`.
- `HumanA` always has a weapon and receives it in its constructor (reference member).
- `HumanB` may or may not have a weapon and receives it later (pointer member).
- Both print `<name> attacks with their <weapon type>`.
- The exercise is about choosing between a reference and a pointer for a member.

### ex04 - Sed is for losers

- Directory: `ex04/`
- Files: `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`
- The program takes a filename and two strings `s1` and `s2`.
- It copies the file to `<filename>.replace`, replacing every occurrence of `s1` with `s2`.
- `std::string::replace` is forbidden.
- C file-manipulation functions are forbidden.
- Handle missing files, empty strings and other errors.

### ex05 - Harl 2.0

- Directory: `ex05/`
- Files: `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`
- `Harl` has private `debug()`, `info()`, `warning()` and `error()` functions.
- `complain(std::string level)` calls the right function using an array of pointers to member functions.
- A forest of `if`/`else if`/`else` is not accepted.

### ex06 - Harl filter

- Directory: `ex06/`
- Files: `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`
- The program takes one level and prints every message from that level and above.
- Example: `WARNING` prints `WARNING` and `ERROR`.
- Unknown level prints `[ Probably complaining about insignificant problems ]`.
- The subject explicitly asks for the `switch` statement.
- Completing this exercise is not mandatory to pass the module.

---

## Module 02 - Ad-hoc polymorphism, operator overloading and OCF

Rank: **04**  
Subject: [`subjects/cpp02.pdf`](subjects/cpp02.pdf)  
Module README: [`CPP_Module_02/README.md`](CPP_Module_02/README.md)

This module introduces the Orthodox Canonical Form and operator overloading through a fixed-point number class. It is the first module where every class must be designed as a complete value type.

### ex00 - My First Class in Orthodox Canonical Form

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
- `Fixed` stores an integer raw value and a static constant number of fractional bits equal to 8.
- Implement the default constructor, copy constructor, copy assignment operator and destructor.
- Implement `getRawBits()` and `setRawBits(int)`.
- Constructors, the assignment operator and `getRawBits()` print messages so the evaluator can see when they are called.
- The default value is 0.

### ex01 - Towards a more useful fixed-point number class

- Directory: `ex01/`
- Files: `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
- Authorized: `roundf` from `<cmath>`.
- Add a constructor from `int` and a constructor from `float`.
- Add `toFloat()` and `toInt()`.
- Overload the insertion operator `<<` to print the floating-point representation.
- The fractional part is always 8 bits.

### ex02 - Now we're talking

- Directory: `ex02/`
- Files: `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
- Authorized: `roundf` from `<cmath>`.
- Overload the six comparison operators, the four arithmetic operators and the four increment/decrement operators.
- Pre/post increment and decrement must change the value by the smallest representable epsilon.
- Add four static `min`/`max` overloads: one pair for non-const references and one pair for const references.

### ex03 - BSP

- Directory: `ex03/`
- Files: `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`, `Point.{h,hpp}`, `Point.cpp`, `bsp.cpp`
- Authorized: `roundf` from `<cmath>`.
- `Point` is in Orthodox Canonical Form and stores two `Fixed const` values `x` and `y`.
- `bsp(Point const a, Point const b, Point const c, Point const point)` returns `true` only when the point is strictly inside the triangle.
- Points on an edge or on a vertex return `false`.
- Completing this exercise is not mandatory to pass the module.

---

## Module 03 - Inheritance

Rank: **04**  
Subject: [`subjects/cpp03.pdf`](subjects/cpp03.pdf)  
Module README: [`CPP_Module_03/README.md`](CPP_Module_03/README.md)

This module is about inheritance, construction/destruction order and multiple inheritance. The recurring theme is a family of robots derived from `ClapTrap`.

### ex00 - Aaaaand... OPEN!

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `ClapTrap.{h,hpp}`, `ClapTrap.cpp`
- `ClapTrap` has a name, 10 hit points, 10 energy points and 0 attack damage.
- `attack(target)`, `takeDamage(amount)` and `beRepaired(amount)`.
- Attacking and repairing cost 1 energy point.
- A ClapTrap with 0 hit points or 0 energy points cannot act.
- Every action and every constructor/destructor prints a message.

### ex01 - Serena, my love!

- Directory: `ex01/`
- Files: previous files plus `ScavTrap.{h,hpp}`, `ScavTrap.cpp`
- `ScavTrap` inherits publicly from `ClapTrap`.
- Its values are 100 hit points, 50 energy points and 20 attack damage.
- Its constructor, destructor and `attack()` print different messages.
- `guardGate()` announces Gate keeper mode.
- The test must show construction and destruction chaining.

### ex02 - Repetitive work

- Directory: `ex02/`
- Files: previous files plus `FragTrap.{h,hpp}`, `FragTrap.cpp`
- `FragTrap` inherits publicly from `ClapTrap`.
- Its values are 100 hit points, 100 energy points and 30 attack damage.
- Its constructor, destructor and messages are different from `ScavTrap`.
- `highFivesGuys()` prints a positive high-five request.

### ex03 - Now it's weird!

- Directory: `ex03/`
- Files: previous files plus `DiamondTrap.{h,hpp}`, `DiamondTrap.cpp`
- `DiamondTrap` inherits from both `FragTrap` and `ScavTrap`.
- It has its own private `name`, with exactly the same variable name as the one in `ClapTrap`.
- Its `ClapTrap` name is the robot name plus `_clap_name`.
- Hit points come from `FragTrap`, energy points from `ScavTrap` and attack damage from `FragTrap`.
- `whoAmI()` prints both the `DiamondTrap` name and the `ClapTrap` name.
- The `ClapTrap` instance must be constructed once and only once: this requires virtual inheritance.
- Completing this exercise is not mandatory to pass the module.

---

## Module 04 - Subtype polymorphism, abstract classes and interfaces

Rank: **04**  
Subject: [`subjects/cpp04.pdf`](subjects/cpp04.pdf)  
Module README: [`CPP_Module_04/README.md`](CPP_Module_04/README.md)

This module formalizes runtime polymorphism: virtual functions, virtual destructors, abstract classes, deep copies and pure abstract classes used as interfaces.

### ex00 - Polymorphism

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`
- `Animal` has a protected `std::string type`.
- `Dog` and `Cat` inherit from `Animal` and set their type to `"Dog"` and `"Cat"`.
- `makeSound()` is virtual and prints the correct sound for each derived class.
- `WrongAnimal` and `WrongCat` show what happens when `makeSound()` is not virtual.
- Constructors and destructors print specific messages.

### ex01 - I don't want to set the world on fire

- Directory: `ex01/`
- Files: previous files plus `Brain.{h,hpp}`, `Brain.cpp`
- `Brain` contains an array of 100 `std::string` ideas.
- `Dog` and `Cat` own a private `Brain*` created with `new Brain()` and deleted in their destructor.
- Deleting a `Dog` or `Cat` through an `Animal*` must call the derived destructor: `Animal` needs a virtual destructor.
- Copies of `Dog` and `Cat` must be deep: the copied brain must not be shared with the original.
- Test an array of `Animal*` half dogs and half cats, then delete them as `Animal*`.
- No leaks.

### ex02 - Abstract class

- Directory: `ex02/`
- Files: previous files
- Make `Animal` abstract by giving `makeSound()` a pure virtual declaration.
- `Animal` can no longer be instantiated and everything else keeps working.
- The class may be renamed `AAnimal`.

### ex03 - Interface & recap

- Directory: `ex03/`
- Files: `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`
- Complete `AMateria` with a protected `type`, `getType()`, a pure virtual `clone()` and a virtual `use(ICharacter&)`.
- Implement `Ice` and `Cure` with types `"ice"` and `"cure"`.
- `Ice::use()` prints `* shoots an ice bolt at <name> *`.
- `Cure::use()` prints `* heals <name>'s wounds *`.
- Implement `ICharacter` and `Character`: 4 inventory slots, `equip`, `unequip`, `use`, deep copy, virtual destructor.
- `unequip()` must not delete the materia.
- Implement `IMateriaSource` and `MateriaSource`: learn up to 4 materia templates and create copies by type.
- Unknown type returns `0`.
- No leaks, including materias dropped on the floor.
- Completing this exercise is not mandatory to pass the module.

---

## Module 05 - Repetition and exceptions

Rank: **05**  
Subject: [`subjects/cpp05.pdf`](subjects/cpp05.pdf)  
Module README: [`CPP_Module_05/README.md`](CPP_Module_05/README.md)

This module introduces exceptions through a bureaucratic world of bureaucrats and forms. It also reinforces inheritance, abstract classes and polymorphism.

### ex00 - Mommy, when I grow up, I want to be a bureaucrat!

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `Bureaucrat.{h,hpp}`, `Bureaucrat.cpp`
- `Bureaucrat` has a constant name and a grade from 1 (highest) to 150 (lowest).
- Invalid construction throws `GradeTooHighException` or `GradeTooLowException`.
- `getName()` and `getGrade()`.
- `incrementGrade()` and `decrementGrade()` throw if the grade leaves the range.
- Overload `<<` to print `<name>, bureaucrat grade <grade>.`
- Exception classes do not have to be in Orthodox Canonical Form.

### ex01 - Form up, maggots!

- Directory: `ex01/`
- Files: previous files plus `Form.{h,hpp}`, `Form.cpp`
- `Form` has a constant name, a signed flag, a sign grade and an execute grade. All attributes are private.
- Invalid grades throw `Form::GradeTooHighException` or `Form::GradeTooLowException`.
- `beSigned(Bureaucrat const&)` signs the form if the grade is high enough, otherwise it throws `GradeTooLowException`.
- `Bureaucrat::signForm(Form&)` signs a form and prints whether it succeeded and why.
- Overload `<<` to print all form information.

### ex02 - No, you need form 28B, not 28C...

- Directory: `ex02/`
- Files: `Makefile`, `main.cpp`, `Bureaucrat.*`, `AForm.*`, `ShrubberyCreationForm.*`, `RobotomyRequestForm.*`, `PresidentialPardonForm.*`
- `Form` becomes the abstract `AForm`.
- `ShrubberyCreationForm`: sign 145, execute 137, creates `<target>_shrubbery` with ASCII trees.
- `RobotomyRequestForm`: sign 72, execute 45, prints drilling noises and succeeds 50% of the time.
- `PresidentialPardonForm`: sign 25, execute 5, prints that the target was pardoned by Zaphod Beeblebrox.
- Each form takes its target in its constructor.
- `execute(Bureaucrat const&) const` checks that the form is signed and that the executor's grade is high enough.
- `Bureaucrat::executeForm(AForm const&)` executes a form and prints the result.

### ex03 - At least this beats coffee-making

- Directory: `ex03/`
- Files: previous files plus `Intern.{h,hpp}`, `Intern.cpp`
- `Intern` has no name and no grade.
- `makeForm(std::string formName, std::string target)` returns a pointer to a new form of the requested type.
- It prints `Intern creates <form>`.
- Unknown form names print an explicit error and return `0`.
- An excessive `if`/`else if`/`else` chain is not accepted: use a lookup table of some kind.

---

## Module 06 - C++ casts

Rank: **05**  
Subject: [`subjects/cpp06.pdf`](subjects/cpp06.pdf)  
Module README: [`CPP_Module_06/README.md`](CPP_Module_06/README.md)

This module is about explicit conversions and the four C++ casts. Every exercise forbids C-style casts in spirit and asks for the correct named cast.

### ex00 - Conversion of scalar types

- Directory: `ex00/`
- Files: `Makefile`, `*.cpp`, `*.{h,hpp}`
- `ScalarConverter` contains only one static method: `convert(std::string const&)`.
- The class must not be instantiable.
- Detect whether the literal is a `char`, `int`, `float` or `double`, convert it to the other three and print all four values.
- Handle `-inff`, `+inff`, `nanf`, `-inf`, `+inf` and `nan`.
- Non-displayable char conversions print `Non displayable`; impossible conversions print `impossible`.
- Handle overflow and invalid literals.

### ex01 - Serialization

- Directory: `ex01/`
- Files: `Makefile`, `*.cpp`, `*.{h,hpp}`
- `Serializer` is not instantiable and provides:
  - `static uintptr_t serialize(Data* ptr);`
  - `static Data* deserialize(uintptr_t raw);`
- `Data` is a non-empty structure with real data members.
- Serialize the address of a `Data` object, deserialize it and verify that the original pointer and the deserialized pointer are equal.
- This exercise is about `reinterpret_cast` and pointer/integer round-trips.

### ex02 - Identify real type

- Directory: `ex02/`
- Files: `Makefile`, `*.cpp`, `*.{h,hpp}`
- Forbidden: `std::typeinfo` and the `<typeinfo>` header.
- `Base` has a public virtual destructor.
- `A`, `B` and `C` inherit publicly from `Base` and are empty.
- `generate()` randomly creates an `A`, `B` or `C` and returns it as `Base*`.
- `identify(Base* p)` prints `A`, `B` or `C`.
- `identify(Base& p)` does the same without using a pointer inside the function.
- The pointer version uses `dynamic_cast` on pointers; the reference version uses `dynamic_cast` on references and catches `std::bad_cast`.

---

## Module 07 - C++ templates

Rank: **05**  
Subject: [`subjects/cpp07.pdf`](subjects/cpp07.pdf)  
Module README: [`CPP_Module_07/README.md`](CPP_Module_07/README.md)

This module introduces function templates and class templates. The key constraint is that template definitions must live in headers (or `.tpp` files included by headers).

### ex00 - Start with a few functions

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `whatever.{h,hpp}`
- Implement `swap(a, b)`, `min(a, b)` and `max(a, b)` as function templates.
- `swap` returns nothing.
- `min` and `max` return the smallest/greatest value; when the values are equal they return the second one.
- The two arguments must have the same type and support the comparison operators.
- Templates must be defined in the header.

### ex01 - Iter

- Directory: `ex01/`
- Files: `Makefile`, `main.cpp`, `iter.{h,hpp}`
- `iter(T* array, size_t length, void (*f)(T&))` applies `f` to every element.
- It must work with any array type and with both const and non-const elements.
- The third parameter may be an instantiated function template.
- The main must contain enough tests to prove it works.

### ex02 - Array

- Directory: `ex02/`
- Files: `Makefile`, `main.cpp`, `Array.{h,hpp}`, optional `Array.tpp`
- `Array<T>` is a class template with:
  - default constructor creating an empty array;
  - constructor taking an `unsigned int n` creating `n` default-initialized elements;
  - copy constructor and copy assignment operator producing independent copies;
  - `operator[]` throwing `std::exception` when the index is out of bounds;
  - `size() const` returning the number of elements.
- Memory must be allocated with `new[]`; preventive allocation is forbidden.
- Never access non-allocated memory.

---

## Module 08 - Templated containers, iterators, algorithms

Rank: **05**  
Subject: [`subjects/cpp08.pdf`](subjects/cpp08.pdf)  
Module README: [`CPP_Module_08/README.md`](CPP_Module_08/README.md)

This is the first module where the STL is allowed. It covers generic functions, containers, iterators and algorithms.

### ex00 - Easy find

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `easyfind.{h,hpp}`, optional `easyfind.tpp`
- Write a function template `easyfind(T& container, int target)`.
- `T` is a container of integers.
- It finds the first occurrence of `target`.
- If there is no occurrence, throw an exception or return an error value. Standard containers throw on failure, so an exception is the natural choice.
- It must work with at least `std::vector`, `std::list` and `std::deque`.
- Associative containers do not have to be supported.

### ex01 - Span

- Directory: `ex01/`
- Files: `Makefile`, `main.cpp`, `Span.{h,hpp}`, `Span.cpp`
- `Span(unsigned int N)` stores at most N integers.
- `addNumber(int)` adds one number and throws if the span is full.
- `shortestSpan()` returns the smallest difference between any two stored numbers.
- `longestSpan()` returns the difference between the largest and the smallest stored number.
- Both throw when there are fewer than two numbers.
- Add a member function that fills the span from a range of iterators.
- Test with at least 10,000 numbers; more is better.
- The reference output for `6, 3, 17, 9, 11` is `2` and `14`.
- This exercise is about avoiding an O(n^2) solution.

### ex02 - Mutated abomination

- Directory: `ex02/`
- Files: `Makefile`, `main.cpp`, `MutantStack.{h,hpp}`, optional `MutantStack.tpp`
- `std::stack` is not iterable.
- Write `MutantStack<T>`, implemented in terms of `std::stack`, offering all stack members plus `begin()` and `end()` iterators.
- The output must match the same test run with `std::list` after adapting the method names.

---

## Module 09 - STL

Rank: **05**  
Subject: [`subjects/cpp09.pdf`](subjects/cpp09.pdf)  
Module README: [`CPP_Module_09/README.md`](CPP_Module_09/README.md)

The last module is a tour of STL containers and algorithms through three practical programs. The container used in one exercise may be forbidden in the next.

### ex00 - Bitcoin Exchange

- Directory: `ex00/`
- Files: `Makefile`, `main.cpp`, `BitcoinExchange.{cpp,hpp}`, plus the provided `data.csv`
- Program name: `btc`.
- It takes an input file as its only argument.
- Each line has the format `date | value`.
- A valid date is `YYYY-MM-DD`.
- A valid value is a float or a positive integer between 0 and 1000.
- For each valid line, print `date => value = result`, where `result` is the value multiplied by the exchange rate for that date.
- If the exact date is not in the database, use the closest **lower** date.
- Error messages:
  - `Error: could not open file.`
  - `Error: bad input => <line>`
  - `Error: not a positive number.`
  - `Error: too large a number.`
- At least one container must be used to validate the exercise. `std::map` is the natural choice for date lookup.
- The container used here cannot be reused in the next exercises.

### ex01 - Reverse Polish Notation

- Directory: `ex01/`
- Files: `Makefile`, `main.cpp`, `RPN.{cpp,hpp}`
- Program name: `RPN`.
- It takes an inverted Polish mathematical expression as its only argument.
- Numbers in the expression are always less than 10, but the result is not limited.
- Supported operators: `+`, `-`, `*`, `/`.
- Invalid expressions print an error on standard error and exit with a non-zero status.
- Brackets and decimal numbers are not required.
- At least one container must be used; `std::stack` is the obvious one.
- The container used here cannot be reused in the next exercise.
- Examples:
  - `8 9 * 9 - 9 - 9 - 4 - 1 +` gives `42`
  - `7 7 * 7 -` gives `42`
  - `1 2 * 2 / 2 * 2 4 - +` gives `0`
  - `(1 + 1)` gives an error

### ex02 - PmergeMe

- Directory: `ex02/`
- Files: `Makefile`, `main.cpp`, `PmergeMe.{cpp,hpp}`
- Program name: `PmergeMe`.
- It takes a sequence of positive integers as arguments.
- It must sort the sequence with the **merge-insertion sort** algorithm, also known as **Ford-Johnson** (Knuth, *The Art of Computer Programming*, Vol. 3, page 184).
- At least two different containers must be used; this repository uses `std::vector` and `std::deque`.
- It must handle at least 3000 different integers.
- Output:
  - `Before: <unsorted sequence>`
  - `After: <sorted sequence>`
  - time for the first container, in microseconds;
  - time for the second container, in microseconds.
- Negative numbers, non-numeric arguments and duplicates are rejected with an error on standard error.
- The precision of the timing must clearly show the difference between the two containers.
- The container used in `ex01` is forbidden here.

---

## Build and run

Every exercise has its own `Makefile`. The default target is `all`, and `make` builds the exercise before printing its success banner.

```bash
cd CPP_Module_04/ex01
make            # build
./Polymorphism  # run
make clean      # remove objects and dependency files
make fclean     # remove objects, dependencies and the binary
make re         # fclean + all
```

The Makefiles use:

```make
CXX      = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
```

Some exercises need extra linker flags. `CPP_Module_00/ex01` links against `readline` and `ncurses` because the phonebook uses `readline()`/`add_history()`.

Examples:

```bash
# Module 00
./CPP_Module_00/ex00/megaphone "hello" "world"
./CPP_Module_00/ex01/phonebook
cd CPP_Module_00/ex02 && ./globalbanksters

# Module 01
./CPP_Module_01/ex00/Zombie
./CPP_Module_01/ex06/violence WARNING

# Module 02
cd CPP_Module_02/ex03 && ./Fixed

# Module 03 / 04
./CPP_Module_03/ex03/scavtrap
./CPP_Module_04/ex03/Polymorphism

# Module 05
./CPP_Module_05/ex03/ex03

# Module 06
./CPP_Module_06/ex00/ex00 42.0f

# Module 07
./CPP_Module_07/ex02/array

# Module 08
./CPP_Module_08/ex00/easyfind
./CPP_Module_08/ex01/span
./CPP_Module_08/ex02/mutantStack

# Module 09
cd CPP_Module_09/ex00 && ./btc input.txt
cd CPP_Module_09/ex01 && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
cd CPP_Module_09/ex02 && ./PmergeMe 3 5 9 7 4
```

A full build check from the repository root:

```bash
for m in CPP_Module_0*; do
  for ex in "$m"/ex*; do
    make -C "$ex" re || exit 1
  done
done
```

---

## Repository layout

```text
CPP_Piscine/
|-- CPP_Module_00/
|   |-- README.md
|   |-- ex00/
|   |-- ex01/
|   `-- ex02/
|-- CPP_Module_01/
|-- CPP_Module_02/
|-- CPP_Module_03/
|-- CPP_Module_04/
|-- CPP_Module_05/
|-- CPP_Module_06/
|-- CPP_Module_07/
|-- CPP_Module_08/
|-- CPP_Module_09/
|-- subjects/
|   |-- cpp00.pdf
|   |-- cpp01.pdf
|   |-- cpp02.pdf
|   |-- cpp03.pdf
|   |-- cpp04.pdf
|   |-- cpp05.pdf
|   |-- cpp06.pdf
|   |-- cpp07.pdf
|   |-- cpp08.pdf
|   `-- cpp09.pdf
|-- LICENSE
`-- README.md
```

Each module directory contains its own `README.md` with exercise-by-exercise details.

---

## Peer-evaluation checklist

Use this checklist before defending any module:

- The project compiles with `c++ -Wall -Wextra -Werror` and with `-std=c++98`.
- `make` builds the executable; `make re` rebuilds it from scratch.
- No `.o`, `.d`, binary or log file is committed.
- No forbidden function: `printf`, `malloc`, `free`, `using namespace`, `friend`.
- No STL container or algorithm before Module 08.
- Classes from Module 02 onward are in Orthodox Canonical Form.
- Copy constructors and assignment operators are deep when the class owns resources.
- Base classes with virtual functions have virtual destructors.
- Copy constructors initialize their base classes explicitly.
- No memory leaks; every `new` has a `delete`/`delete[]`.
- Headers are independent and have include guards.
- Template definitions are in headers or `.tpp` files.
- Error cases are handled: invalid input, missing files, out-of-range values, empty containers.
- Output matches the subject format, including newlines and error messages.
- The student can explain every line and survive a small live modification.

Common mistakes found and fixed in this repository:

- Makefile whose default target printed a banner but did not build the project.
- Makefile that built a binary with the wrong name (`07/ex01` produced `ex00`).
- Missing `-Wall -Wextra -Werror` in `03/ex03`.
- Copy constructors that did not initialize their base class (`03/ex01`, `03/ex02`, `03/ex03`, `04/ex01`, `04/ex02`).
- A `switch` fallthrough treated as an error by `-Werror` (`01/ex06`).
- Undefined colour macros and missing function declarations in `08/ex00` and `08/ex01`.
- Missing braces around a `try` block in `09/ex01` and `09/ex02`.
- `std::numeric_limits` used without `<limits>` in `08/ex01`.
- Missing `-lreadline -lncurses` in `00/ex01`.
- A PmergeMe implementation that lost elements during recursive sorting.
- A BitcoinExchange implementation that did not validate dates and numeric values.

---

## Credits

- 42 Madrid / 42 Common Core, for the subjects and the project definitions.
- Ismael Hernandez (`ismherna@student.42.fr` / `ismherna@student.42madrid.com`), author of the implementations.
- The subjects are the property of 42 and are included here only for study and evaluation purposes.

See [`LICENSE`](LICENSE) for the license of the code in this repository.
