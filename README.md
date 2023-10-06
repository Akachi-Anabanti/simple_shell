# SIMPLE Shell in C

## Overview

This project is a simple implementation of a BASH-like shell in C. It provides both interactive and non-interactive modes for executing commands. The shell supports basic built-in commands and allows the execution of external programs.

## Features

- **Interactive mode:** User can type commands directly into the shell.
- **Non-interactive mode:** Commands can be provided through scripts or as command-line arguments.
- **Command execution:** Executes both built-in and external commands.
- **Built-in commands:** Supports common shell built-ins like `cd`, `pwd`, `echo`, and `exit`.
- **Pipelines and redirections:** Supports command pipelines (e.g., `command1 | command2`) and input/output redirections (e.g., `command < input.txt` or `command > output.txt`).

## Getting Started

### Prerequisites

- C compiler (e.g., GCC)
- Linux or Unix-like environment (for system calls and features)

### Compilation

Compile the shell using the provided Makefile:

```bash
make
```

### Running the Shell

To start the interactive shell, simply run:

```bash
./shell
```

To execute commands in non-interactive mode, you can provide a script file:

```bash
./shell -f script.txt
```

Or run a single command directly:

```bash
./shell -c "ls -l"
```

## Usage

Once in the shell, you can use standard BASH-like syntax to enter and execute commands. Here are some examples:

- Run a simple command:

  ```bash
  $ ls -l
  ```

- Use built-in commands:

  ```bash
  $ cd /path/to/directory
  $ pwd
  $ echo "Hello, World!"
  $ exit
  ```

- Create pipelines:

  ```bash
  $ ls -l | grep .txt
  ```

- Redirect input/output:

  ```bash
  $ cat < input.txt
  $ ls > output.txt
  ```

## Supported Built-in Commands

- `cd`: Change the current working directory.
- `pwd`: Print the current working directory.
- `echo`: Print text to the standard output.
- `exit`: Exit the shell.

## Limitations

- Limited error handling and error messages.
- Limited support for advanced features like aliases, scripting constructs, and shell options.
- Not fully POSIX compliant, so some complex scripts may not work as expected.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests to help improve this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

This project was inspired by the BASH shell and various Unix-like shells. Special thanks to the open-source community for their contributions to the field of shell scripting and programming and Julien for ALX Software Engineering School.
