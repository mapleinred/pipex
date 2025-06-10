# pipex

## Project Overview

**pipex** is a 42 school system programming project that aims to deepen understanding of UNIX process management, inter-process communication, and file descriptor manipulation. The goal is to recreate the shell’s pipe (`|`) functionality in C, handling multiple commands, redirections, and even heredoc input (bonus).

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [How to Build](#how-to-build)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [What I Learned](#what-i-learned)
- [Design Decisions](#design-decisions)
- [Challenges & Solutions](#challenges--solutions)
- [Skills Demonstrated](#skills-demonstrated)
- [Future Improvements](#future-improvements)

## Features

- Executes two or more commands with UNIX pipes, simulating shell pipelines.
- Handles input/output file redirection.
- Supports heredoc functionality (bonus).
- Robust error handling and resource management.
- Modular code structure and custom implementation of standard C library functions (libft).

## Project Structure

```
pipex/
├── Makefile
├── include/
│   ├── pipex.h
│   └── pipex_bonus.h
├── libft/
│   └── ... (custom C library functions)
└── srcs/
    ├── pipex.c
    ├── pipex_utils.c
    ├── pipex_bonus.c
    └── pipexbonus_utils.c
```

## How to Build

Compile the project using the provided Makefile:

```sh
make
# For bonus (heredoc and multiple pipes)
make bonus
```

## Usage

**Basic usage (two commands):**
```sh
./pipex infile "cmd1" "cmd2" outfile
```
Equivalent to:
```sh
< infile cmd1 | cmd2 > outfile
```

**Bonus (heredoc and multiple commands):**
```sh
./pipex_bonus here_doc LIMITER "cmd1" "cmd2" ... "cmdn" outfile
```
Equivalent to:
```sh
cmd << LIMITER | cmd1 | ... | cmdn >> outfile
```

## Implementation Details

- Uses `pipe()` to create communication channels between processes.
- Employs `fork()` to spawn child processes for each command.
- Utilizes `execve()` to execute commands, searching for executables in the system `PATH`.
- Manages file descriptors with `dup2()` for input/output redirection.
- Implements custom string and memory functions via `libft`.
- Handles all error cases gracefully, ensuring no resource leaks.
- Bonus: Implements heredoc by reading from stdin until a limiter is reached, then piping the input to the first command.

## What I Learned

- Deep understanding of UNIX system calls: `open`, `close`, `read`, `write`, `pipe`, `fork`, `execve`, `dup2`, `waitpid`.
- Practical experience with process creation, synchronization, and inter-process communication.
- Advanced file descriptor management and redirection techniques.
- Parsing and handling environment variables (`PATH`).
- Writing modular, maintainable, and well-documented C code.
- Creating and using Makefiles for project automation.
- Debugging and memory management using tools like Valgrind.

## Design Decisions

- **Modular Structure:** Separated code into logical modules (`srcs`, `include`, `libft`) for clarity and maintainability.
- **Custom Libft:** Reused self-written standard C functions to reinforce understanding and avoid external dependencies.
- **Error Handling:** Centralized error management to ensure robust and predictable behavior.
- **Resource Management:** Carefully closed unused file descriptors and freed all allocated memory to prevent leaks.

## Challenges & Solutions

- **Deadlocks and Zombie Processes:** Initially encountered deadlocks due to improper file descriptor management. Solved by closing all unused ends of pipes in both parent and child processes and using `waitpid` for process synchronization.
- **PATH Resolution:** Faced issues with command not found errors. Implemented a robust function to parse the `PATH` environment variable and check executable permissions with `access()`.
- **Memory Leaks:** Detected and fixed memory leaks by systematically freeing all dynamically allocated memory and using Valgrind for verification.
- **Heredoc Implementation:** Simulating shell heredoc behavior required careful handling of stdin and temporary buffers, which was achieved by reading input until the limiter and piping it to the next process.

## Key Takeaways

- Gained hands-on experience with inter-process communication and file descriptor management.
- Learned to design robust error handling and resource cleanup strategies.
- Improved ability to read, understand, and implement UNIX manual pages.

## Future Improvements

- Add support for more complex shell features (e.g., environment variable expansion, wildcards).
- Implement more comprehensive unit and integration tests.
- Refactor code for even greater modularity and reusability.
- Add CI/CD pipeline for automated builds and tests.


