# 🔗 C Implementation of a Circular Doubly-Linked List with Sentinel Node

## Overview

This project provides a robust, low-level implementation of a **circular doubly-linked list** in **C**. A key design choice is the use of a **sentinel node**, which significantly simplifies the logic for handling boundary conditions (like inserting/deleting at the start/end) and results in cleaner, more efficient code for all primary list operations. The implementation focuses on proper memory and pointer management crucial for C programming.



## Implementation Details

### Data Structures

| Structure | Purpose |
| :--- | :--- |
| `struct node` | Represents an individual element, containing user data and two pointers (`next`, `prev`) to adjacent nodes. |
| `struct list` | Represents the entire list structure, holding a pointer to the **sentinel node** which acts as the fixed head/tail anchor. |

### Core Functions (14 Functions)

The implementation includes a full set of functions for dynamic list manipulation, many of which operate in $O(1)$ time due to the sentinel structure:

* **Initialization and Cleanup**: `newList()`, `freeList()` (deallocates all nodes, including the sentinel).
* **Insertion**: `insertAfter()`, `insertBefore()`, and other related functions.
* **Deletion**: `deleteNode()` and functions to remove nodes by position or data.
* **Traversal**: `moveNext()`, `movePrev()`, and functions to retrieve data from the current node pointer.
* **Utility**: Functions for checking if the list is empty, determining the size, etc.

### Compilation and Usage

The program is compiled using the standard C toolchain.

### 🛠 Development Environment

* GCC compiler (`clang` on macOS)
* Standard C library
* `Makefile` (provided in the original coursework)

### 🚀 Compilation Example

```bash
# Compile using rigorous checking and debugging flags
clang -std=c11 -Wall -pedantic -g -fsanitize=undefined -fsanitize=address list.c -o list_program
