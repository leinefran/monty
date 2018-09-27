<img src="https://www.holbertonschool.com/assets/holberton-logo-1cc451260ca3cd297def53f2250a9794810667c7ca7b5fa5879a569a457bf16f.png" alt="Holberton logo">

# 0x18. C - Stacks, Queues - LIFO, FIFO
---
## Name

Monty Translator

## Description

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### This project in the Lower Level Programming series is about:

 * What do LIFO and FIFO mean
 * What is a stack, and when to use it
 * What is a queue, and when to use it
 * What are the common implementations of stacks and queues
 * What are the most common use cases of stacks and queues
 * What is the proper way to use global variables
 * How to work with git submodules

## Requirements

 * Allowed editors: vi, vim, emacs
 * All your files will be compiled on Ubuntu 14.04 LTS
 * Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
 * All your files should end with a new line
 * A README.md file, at the root of the folder of the project is mandatory
 * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
 * You allowed to use a maximum of one global variable
 * No more than 5 functions per file
 * You are allowed to use the C standard library
 * The prototypes of all your functions should be included in your header file called monty.h
 * Don’t forget to push your header file
 * All your header files should be include guarded
 * You are expected to do the tasks in the order shown in the project
 * The repository monty should be added as a submodule to your holbertonschool-low_level_programming repository, under the name 0x18-stacks_queues_lifo_fifo


---
File|Task
---|---
README.md | read me file
add.c | a function that adds the top two elements of the stack and more
add_node_end.c | a function adds a new node at the end of a `list_t` linked list
error_handling.c | a program that handles error messages
free_functions.c | a program that handles memory leaks
get_instruc_func.c | a function that reads command string and selects the correct function to perform
get_opcode_at_node_index.c | a function that returns the value of node at line number
get_value_at_node_index.c | a function that returns the value of node at line number
isnumber.c | checks if the argv[2] is a number
main.c | the main function
monty.h | the header file
pall.c | a function that prints all the values on the stack, starting from the top of the stack
pint.c | a function that prints the value at the top of the stack, followed by a new line
pop.c | a function that removes the top element of the stack
push.c | a function that pushes an element to the stack
swap.c | a function that swaps the top two elements of the stack
tokenize_functions.c | a program that handles arguments passed to the program monty


#### Compilation

Files are compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

### Authors

[Jinji](https://github.com/iamzinzi)

[Leine Valente](https://github.com/leinefran)