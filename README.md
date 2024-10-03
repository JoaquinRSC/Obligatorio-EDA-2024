# Obligatorio-EDA-2024

## Overview

This project is related to a C program, likely focused on handling business-related logic (based on the file names `empresa.c` and `empresa.h`). The project is structured to be compiled using a `makefile`, and it includes several header and source files to define and implement functionality.

## Project Structure

- **makefile**: Automates the build process, containing instructions to compile the project and generate the executable.
- **definiciones.h**: Contains macro definitions, constants, or other global definitions used across the project.
- **empresa.h**: Defines the structures and function prototypes related to the business logic.
- **empresa.c**: Implements the functions declared in `empresa.h`, likely focusing on managing business-related operations.
- **main.c**: Contains the `main()` function, which serves as the entry point of the program.

## How to Build

To compile the project, use the provided `makefile`. Ensure you have `make` installed on your system, then run the following command in the project directory:

```bash
make
```

## How to Run

Once the project is compiled, you can run the resulting executable by executing the following command in your terminal:

```bash
./<executable_name>
```

Replace `<executable_name>` with the name of the compiled file (this is likely specified in the `makefile`).

## Requirements

- **GCC** (GNU Compiler Collection): Required to compile C source code.
- **Make**: Required to process the `makefile` and automate the build process.
