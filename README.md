# Obligatorio-EDA-2024

## Project Structure

- **makefile**: Automates the build process, containing instructions to compile the project and generate the executable.
- **definiciones.h**: Contains macro definitions, constants, or other global definitions used across the project.
- **empresa.h**: Defines the structures and function prototypes related to the business logic.
- **empresa.c**: Implements the functions declared in `empresa.h`, likely focusing on managing business-related operations.
- **persona.h**: Defines the structure and prototypes for handling personnel-related operations.
- **persona.c**: Implements the functions declared in `persona.h`, managing personnel data.
- **cargo.h**: Defines the structure and prototypes for handling job roles within the organization.
- **cargo.c**: Implements the functions declared in `cargo.h`, managing job-related operations.
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
