# 📚 Object-Oriented Library Management System

### C++ Programming Fundamentals – Coursera Capstone Project

---

## Overview

This project is a **Coursera Capstone Project** developed as part of the **C++ Programming Fundamentals** course. It implements a simple **Library Management System** using Object-Oriented Programming (OOP) principles in C++.

The project demonstrates class design, inheritance, polymorphism, abstraction, exception handling, and smart pointers while simulating basic library operations such as checking out and returning books.

---

## Features

* Create and manage library books
* Check out and return books
* Track book availability
* Calculate overdue fines
* Handle invalid operations using custom exceptions
* Automatic memory management using `std::unique_ptr`
* Clean and modular object-oriented design

---

## OOP Concepts Demonstrated

* **Encapsulation**
* **Inheritance**
* **Abstraction**
* **Polymorphism**
* **Exception Handling**
* **Smart Pointers (RAII)**

---

## Technologies Used

* C++
* Standard Template Library (STL)
* Object-Oriented Programming
* Smart Pointers (`std::unique_ptr`)
* Exception Handling

---

## Project Structure

```text
Library Management System
│
├── Custom Exception Classes
│   ├── LibraryException
│   ├── CheckoutException
│   ├── ReturnException
│   ├── ItemNotFoundException
│   ├── PatronNotFoundException
│   └── ValidationException
│
├── LibraryItem (Abstract Base Class)
│
└── Book (Derived Class)
```

---

## Sample Book Used

* **Title:** Barça: The Illustrated History of FC Barcelona
* **Author:** Simon Kuper
* **Genre:** Sports
* **ISBN:** 9780241304969
* **Pages:** 400
* **Published:** 2018

---

## Sample Output

```text
Item Type : Book
Book Title: Barça: The Illustrated History of FC Barcelona
Book Info : Author: Simon Kuper, ISBN: 9780241304969, Genre: Sports, Pages: 400, Year: 2018

Book checked out successfully!
Checkout Error: Item is already checked out.
```

---

## Learning Outcomes

Through this Coursera capstone project, I learned how to:

* Apply Object-Oriented Programming concepts in C++
* Design reusable and extensible classes
* Implement inheritance and runtime polymorphism
* Use abstract classes and virtual functions
* Handle runtime errors with custom exceptions
* Manage memory safely using smart pointers
* Build a modular and maintainable C++ application

---

## Future Enhancements

* Add Patron Management
* Support multiple library item types
* Search books by title, author, or ISBN
* File handling for persistent storage
* Due-date tracking and fine management
* Menu-driven console interface

---

## Author

**Akkshath Magar**

B.Tech Computer Science Engineering (CSE)

SRM Institute of Science and Technology

---

## Course

**C++ Programming Fundamentals – Coursera**

**Project:** Object-Oriented Library Management System (Capstone Project)

---

## License

This project was developed as part of a Coursera learning project and is intended for educational purposes.
