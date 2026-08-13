# Generalised Data Structures Library

A **generic data structure library implemented in C++ using templates**, designed to provide reusable implementations of commonly used linear and non-linear data structures.

The project focuses on applying **Object-Oriented Programming, templates, pointers, dynamic memory allocation, and data structure concepts** to build reusable and type-independent implementations.

---

## Features

* Generic implementations using C++ templates
* Reusable data structures
* Support for linear data structures
* Support for non-linear data structures
* Searching operations
* Sorting operations
* Insertion and deletion operations
* Traversal operations
* Object-Oriented design
* Type-independent implementations

---

## Technologies

* **Language:** C++
* **Concept:** Generic Programming
* **Core:** Data Structures & Algorithms
* **Programming Paradigm:** Object-Oriented Programming
* **Compiler:** GCC / G++

---

## Why Templates?

The library uses C++ templates to make the data structures **generic and reusable**.

Instead of implementing the same data structure separately for different data types:

```cpp
int
float
char
string
```

a template-based implementation can work with multiple types.

```cpp
template <class T>
class DataStructure
{
    // Generic implementation
};
```

This improves:

* Code reusability
* Type flexibility
* Maintainability
* Scalability

---

## Data Structures

The project contains implementations of commonly used data structures.

### Linear Data Structures

* Arrays
* Linked Lists
* Stacks
* Queues

### Non-Linear Data Structures

* Trees
* Binary Search Trees
* Other tree-based structures

> The exact data structures included depend on the implementations present in the repository.

---

## Tree Operations

The tree-based implementations demonstrate common traversal and structural operations such as:

```text
             Tree
              │
      ┌───────┴───────┐
      ▼               ▼
   Traversal       Searching
      │
 ┌────┼─────┐
 ▼    ▼     ▼
Inorder Preorder Postorder
```

These operations provide practical experience with recursive algorithms and hierarchical data structures.

---

## Searching

The project includes searching techniques designed to efficiently locate elements within data structures.

Examples include:

* Linear Search
* Binary Search
* Tree-based Searching

---

## Sorting

Sorting algorithms can be implemented and tested using different data types through the generic template-based design.

The template approach allows the same algorithmic logic to operate on different types without rewriting the implementation.

---

## Generic Architecture

```text
                Generic Data Structure
                         │
                         ▼
                 template <class T>
                         │
          ┌──────────────┼──────────────┐
          ▼              ▼              ▼
        int            float          char
          │              │              │
          └──────────────┼──────────────┘
                         ▼
                Reusable Operations
```

---

## Example

A generic class can be instantiated with different data types:

```cpp
DataStructure<int> obj1;

DataStructure<float> obj2;

DataStructure<char> obj3;
```

The same implementation can therefore be reused for different types.

---

## Project Structure

```text
Generalised-Data-Structure/
│
├── Array/
├── LinkedList/
├── Stack/
├── Queue/
├── Tree/
│
├── Searching/
├── Sorting/
│
└── README.md
```

> Update the folder names above to match the actual structure of the repository.

---

## Compilation

Compile an individual C++ implementation using:

```bash
g++ filename.cpp -o program
```

Run:

```bash
./program
```

On Windows:

```bash
g++ filename.cpp -o program.exe
program.exe
```

---

## Concepts Demonstrated

This project provides practical experience with:

* C++ Programming
* Generic Programming
* C++ Templates
* Data Structures
* Algorithms
* Object-Oriented Programming
* Pointers
* Dynamic Memory Allocation
* Recursion
* Searching
* Sorting
* Tree Traversals
* Code Reusability

---

## Learning Objectives

The project was developed to strengthen understanding of:

* Implementing data structures from scratch
* Designing reusable generic classes
* Applying templates to real data structures
* Understanding time and space trade-offs
* Working with pointers and dynamic memory
* Implementing recursive algorithms
* Building modular and reusable C++ code

---

## Future Improvements

* Add comprehensive unit testing
* Add complexity analysis for each operation
* Add iterator support
* Add exception handling
* Improve documentation for individual data structures
* Add benchmarking for different implementations
* Expand the collection of generic data structures
* Add examples for each data structure

---

## Author

**Yash Kundalwal**

B.Tech in Artificial Intelligence & Data Science
Vishwakarma Institute of Information Technology, Pune

[GitHub](https://github.com/yashkundalwal)

[LinkedIn](https://linkedin.com/in/yash-kundalwal)
