# Expression Evaluator

A C program that performs various expression conversions and evaluations using stack data structures.

## Features

- Convert infix expressions to postfix notation
- Convert infix expressions to prefix notation
- Convert postfix expressions to prefix notation
- Convert prefix expressions to postfix notation
- Evaluate postfix expressions
- Evaluate prefix expressions

## Requirements

- GCC compiler
- Make utility

## Building the Project

To build the project, simply run:

```bash
make
```

This will create an executable named `expression_evaluator`.

## Running the Program

Run the program using:

```bash
./expression_evaluator
```

## Usage

The program provides a menu-driven interface with the following options:

1. Convert Infix to Postfix
2. Convert Infix to Prefix
3. Convert Postfix to Prefix
4. Convert Prefix to Postfix
5. Evaluate Postfix Expression
6. Evaluate Prefix Expression
7. Exit

### Input Format

- Infix expressions should be properly parenthesized
- Use single-digit numbers (0-9) for evaluation
- Supported operators: +, -, *, /, ^
- No spaces between characters

### Examples

- Infix: `(2+3)*4`
- Postfix: `23+4*`
- Prefix: `*+234`

## Cleaning Up

To clean up the compiled files, run:

```bash
make clean
```

## Implementation Details

- Uses stack data structure for all operations
- Shows step-by-step visualization of the stack contents
- Includes 2-second pauses between steps for better understanding
- Handles operator precedence and associativity
- Provides clear error messages for invalid inputs
