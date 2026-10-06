# C Programming Projects & Tutorials

A collection of C programming exercises, experiments, and small command-line applications developed while building a stronger foundation in C programming and low-level software development.

The repository progresses from fundamental C concepts to more practical programs involving functions, arrays, strings, structures, file handling, sorting, and interactive command-line applications.

## Purpose

I created this repository to strengthen my understanding of C and develop the programming fundamentals required for systems and embedded-software development.

The exercises focus on understanding how C programs work at a lower level, including:

* Variables and data types
* Control flow
* Functions
* Arrays
* Strings
* Pointers and memory-related concepts
* Structures
* File I/O
* Command-line interaction
* Basic algorithms
* Data manipulation

The repository also contains small applications that combine several of these concepts into working programs.

## Repository Contents

### C Fundamentals

The introductory exercises cover topics such as:

* Variables and data types
* Character handling
* Strings
* Loops
* Conditional statements
* Functions
* Basic calculations
* Input and output
* Array manipulation

Examples include:

* `basics.c`
* `chars.c`
* `loops.c`
* `strings.c`
* `area.c`
* `celsius_fahrenheit.c`
* `simpleInterest.c`
* `prime-num.c`
* `swap.c`

### Arrays and Algorithms

The repository contains exercises involving:

* Array traversal
* Array manipulation
* Sorting
* Searching
* Basic algorithmic problem solving

For example, `c_tuts/sorting.c` implements a basic sorting algorithm and demonstrates passing an array to a function for modification.

### Structures

The repository includes examples using C structures to represent related data.

For example, `structs.c` defines a `Point` structure containing `x` and `y` coordinates and works with an array of `Point` structures.

The larger examples also use structures to model application data such as contacts and books.

### File Handling

Several exercises explore working with files using the C standard library.

These include:

* Opening and closing files
* Reading from files
* Writing to files
* Appending data
* Working with text files
* Working with binary files
* Persisting application data

Examples include:

* `files.c`
* `c_tuts/contact_system.c`
* `c_tuts/testContact.c`
* `c_tuts/quiz.c`

### Command-Line Applications

The repository contains several small interactive applications that combine multiple C concepts.

#### Contact Management System

`c_tuts/contact_system.c`

A command-line contact management application supporting:

* Adding contacts
* Searching for contacts
* Updating contacts
* Deleting contacts
* Displaying contacts
* Persistent storage using a binary file

The application uses a `Contact` structure and file operations to store and retrieve contact records.

#### Quiz Application

`c_tuts/quiz.c`

A command-line quiz application that demonstrates:

* Structures
* Arrays
* File reading
* String processing
* Randomization
* User input
* Score calculation
* Result persistence

Questions are loaded from a file, shuffled, presented to the user, and the resulting score is saved to a results file.

#### Book Shop Inventory Exercise

`c_tuts/book_shop_inventory.c`

An exercise involving structured records representing books, including:

* Author
* Title
* Price
* Publication date
* Publisher
* Quantity

The program demonstrates searching structured records and calculating the cost of requested quantities based on available stock.

## My Contribution

This repository represents my personal C programming practice and experimentation.

My contribution includes:

* Writing and modifying the C source files
* Implementing the exercises and small applications
* Designing data structures for examples such as contacts and books
* Implementing functions for searching, sorting, file handling, and data manipulation
* Compiling and running the programs locally
* Debugging compilation and runtime issues
* Experimenting with different approaches to understand C programming concepts

Some exercises are based on concepts and examples from C programming learning materials. Where applicable, the repository should therefore be understood as a learning portfolio rather than a collection of entirely original production applications.

## Technologies and Tools

### Programming Language

* C

### Standard C Libraries

The projects make use of standard libraries including:

* `stdio.h`
* `stdlib.h`
* `string.h`
* `ctype.h`
* `time.h`

### Development Tools

* GCC / C compiler
* Visual Studio Code
* Command-line terminal
* Git / GitHub

## Testing

The programs were tested locally by compiling and executing the individual C source files.

The general testing workflow was:

1. Compile the source code using a C compiler.
2. Resolve compilation errors and warnings where encountered.
3. Run the resulting executable from the terminal.
4. Provide different inputs to exercise the program's logic.
5. Verify the resulting output.
6. For file-based programs, inspect the generated or modified files to verify persistence.

For interactive programs such as the contact management system and quiz application, I tested different user-input paths and verified that the expected operations and output were produced.

For algorithmic exercises such as sorting, I compared the output before and after the operation to verify that the data was correctly rearranged.

## Examples of Concepts Demonstrated

| Area                   | Examples                                 |
| ---------------------- | ---------------------------------------- |
| Variables & data types | `basics.c`                               |
| Control flow           | `loops.c`, quiz exercises                |
| Strings                | `strings.c`, contact system              |
| Arrays                 | Array and sorting exercises              |
| Functions              | Sorting, searching and utility functions |
| Structures             | `structs.c`, contact and book records    |
| File I/O               | `files.c`, contact system, quiz          |
| Algorithms             | Sorting and searching                    |
| User interaction       | Contact system, quiz, book inventory     |
| Data persistence       | Contacts and quiz results                |

## Learning Outcomes

Working through these exercises gave me practical experience with:

* Writing procedural programs in C
* Breaking programs into functions
* Working with arrays and strings
* Designing and using structures
* Passing data to functions
* Reading and writing files
* Building interactive command-line applications
* Implementing basic algorithms
* Debugging compilation and runtime problems
* Understanding the programming fundamentals behind lower-level software

## Future Development

This repository represents part of my foundation in C programming. I intend to build on these fundamentals through more structured embedded-systems and systems-programming work, particularly around:

* Memory management
* Pointers and pointer arithmetic
* Bitwise operations
* Data structures and algorithms
* Embedded C
* Microcontroller programming
* Hardware interfaces
* Communication protocols
* Testing and validation
* Real-time and resource-constrained systems
