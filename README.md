# Programming Assignment #3 — Structs and Memory Management in C

## Overview
This assignment involves working with C structs and memory management concepts such as dynamic allocation, function implementation, and testing. The project includes various functions to create, manipulate, copy, and manage employee records using struct pointers.

## Features
- Implements struct-based employee records.
- Allocates and initializes structs dynamically.
- Supports shallow and deep copying of struct arrays.
- Generates and processes random employee data.

## Prerequisites
- A C compiler (e.g., `gcc`)
- Standard C libraries
- Linux or macOS (or Windows with WSL)

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/your-repository/HW3_B.git
   cd HW3_B
   ```
2. Compile the program:
   ```sh
   gcc -o HW3B mystruct.c production.c tests.c HW3B.c -Wall -Wextra
   ```

## Usage
Run the program with:
```sh
./HW3B
```

## Implementation Details
- `makeEmployee()`: Creates an employee struct with provided attributes.
- `generateRandomEmployee()`: Generates an employee struct with random values.
- `allocateEmployeeArray()`: Allocates an array of employee structs.
- `printEmployee()`: Displays an employee's details.
- `copyEmployeeArray()`: Performs a shallow copy of an employee struct array.
- `deepCopyEmployeeArray()`: Performs a deep copy of an employee struct array.
- `freeEmployeeArray()`: Frees dynamically allocated employee structs.

## Input File Format (If Required)
Some parts of the assignment may involve reading from input files. The expected format includes structured employee data with each field on a separate line.

Example format:
```
John Doe
1985
2010
```

## Testing
- The program includes unit tests in `tests.c`.
- Ensure test coverage for all implemented functions.
- Use random data generation functions to validate behavior.

## Additional Notes
- Uses `rand()` for random data generation.
- Manages memory dynamically with `malloc()` and `free()`.
- Demonstrates both shallow and deep copying techniques.
- Includes structured function headers for documentation.

## Example Execution
```sh
./HW3B
Employee Name: John Doe
Birth Year: 1985
Start Year: 2010
```
