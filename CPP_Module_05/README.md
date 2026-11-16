# CPP Module 05 - Repetition and Exceptions

<img width="1657" height="308" alt="CPP Module 05" src="https://github.com/user-attachments/assets/d5407180-c50a-4954-b1f6-0923079c113d" />

- **Rank:** 05
- **Language:** C++98
- **Subject:** [subjects/cpp05.pdf](../subjects/cpp05.pdf)
- **Root documentation:** [../README.md](../README.md)

## Overview

Module 05 opens the second half of the CPP piscine. It introduces exceptions through a bureaucratic world of bureaucrats, forms and interns. The theme is humorous, but the C++ content is serious: custom exception classes, exception safety, abstract base classes, polymorphism and object factories.

The module also reinforces inheritance and the Orthodox Canonical Form: every class except the exception classes must be canonical.

## Learning objectives

- Throw and catch exceptions.
- Design custom exception classes that derive from `std::exception`.
- Keep objects in valid states when operations fail.
- Use abstract base classes with polymorphic behaviour.
- Implement an object factory without a long `if`/`else` chain.
- Manage ownership of dynamically created forms.

## Key concepts

### Exceptions

An exception transfers control to the nearest matching `catch` block. The subject requires exceptions to be catchable as `std::exception&`:

```cpp
try
{
    Bureaucrat bob("Bob", 0);
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

Custom exceptions should override:

```cpp
virtual const char* what() const throw();
```

### Grade semantics

Grades range from 1 (highest) to 150 (lowest). Increasing a grade means moving toward 1; decreasing means moving toward 150. An invalid grade throws `GradeTooHighException` when it would go below 1 and `GradeTooLowException` when it would exceed 150.

### Abstract forms

In `ex02`, `Form` becomes `AForm`, an abstract class with a pure virtual `execute()` hook. Concrete forms implement their action while the base class enforces the sign/grade checks.

### Factory

`Intern::makeForm()` maps a form name to a constructor. A lookup table is cleaner than a chain of `if`/`else if` and is what the subject expects.

## Exercises

### ex00 - Mommy, when I grow up, I want to be a bureaucrat!

- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `Bureaucrat.{h,hpp}`, `Bureaucrat.cpp`
- `Bureaucrat` has:
  - a constant name;
  - a grade between 1 and 150.
- Invalid construction throws `Bureaucrat::GradeTooHighException` or `Bureaucrat::GradeTooLowException`.
- Getters: `getName()`, `getGrade()`.
- `incrementGrade()` and `decrementGrade()` throw if the grade leaves the range.
- Overload `operator<<` to print:

```text
<name>, bureaucrat grade <grade>.
```

- Exception classes do not have to be in Orthodox Canonical Form.

### ex01 - Form up, maggots!

- **Directory:** `ex01/`
- **Files:** previous files plus `Form.{h,hpp}`, `Form.cpp`
- `Form` has:
  - a constant name;
  - a boolean signed flag, initially false;
  - a constant sign grade;
  - a constant execute grade;
  - all attributes private.
- Invalid grades throw `Form::GradeTooHighException` or `Form::GradeTooLowException`.
- Getters for every attribute.
- `beSigned(Bureaucrat const&)` signs the form if the bureaucrat's grade is high enough; otherwise it throws `Form::GradeTooLowException`.
- `Bureaucrat::signForm(Form&)` calls `beSigned()` and prints either:
  - `<bureaucrat> signed <form>`;
  - `<bureaucrat> couldn't sign <form> because <reason>.`
- Overload `operator<<` to print all form information.

### ex02 - No, you need form 28B, not 28C...

- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`, `Bureaucrat.*`, `AForm.*`, `ShrubberyCreationForm.*`, `RobotomyRequestForm.*`, `PresidentialPardonForm.*`
- `Form` becomes the abstract `AForm`.
- Concrete forms:
  - `ShrubberyCreationForm`: sign 145, execute 137; creates `<target>_shrubbery` with ASCII trees.
  - `RobotomyRequestForm`: sign 72, execute 45; prints drilling noises and succeeds 50% of the time.
  - `PresidentialPardonForm`: sign 25, execute 5; prints that the target was pardoned by Zaphod Beeblebrox.
- Each form takes its target in its constructor.
- `AForm::execute(Bureaucrat const& executor) const` checks:
  - the form is signed;
  - the executor's grade is high enough.
- `Bureaucrat::executeForm(AForm const& form) const` attempts execution and prints the result.
- Handle insufficient grades and unsigned forms with explicit exceptions.

### ex03 - At least this beats coffee-making

- **Directory:** `ex03/`
- **Files:** previous files plus `Intern.{h,hpp}`, `Intern.cpp`
- `Intern` has no name and no grade.
- `AForm* makeForm(std::string formName, std::string target)` returns a new form of the requested type.
- It prints `Intern creates <form>`.
- Unknown names print an explicit error and return `0`.
- An excessive `if`/`else if`/`else` chain is rejected; use an array of function pointers or a similar table.

Example:

```cpp
Intern someRandomIntern;
AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
```

## Build and run

```bash
cd CPP_Module_05/ex00 && make && ./Bureaucrat
cd CPP_Module_05/ex01 && make && ./form
cd CPP_Module_05/ex02 && make && ./bureaucrat
cd CPP_Module_05/ex03 && make && ./ex03
```

Some forms create files such as `<target>_shrubbery`; remove them after testing or keep them out of git.

## Evaluation notes

- Every non-exception class must be in Orthodox Canonical Form.
- Exceptions must be catchable as `std::exception&`.
- Do not leak dynamically created forms; `Intern::makeForm()` returns ownership to the caller.
- `executeForm()` must not crash on an unsigned form or an insufficient grade.
- The intern factory must not be a long conditional chain.
- STL containers and algorithms are forbidden.
