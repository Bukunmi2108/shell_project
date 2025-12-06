# MyShell

A custom shell implementation in C, featuring standard shell functionalities and an integrated AI chat mode powered by Google's Gemini API.

============================================

```
     ▄▄▄▄    █    ██  ██ ▄█▀ █    ██  ███▄    █  ███▄ ▄███▓ ██▓  ██████      ██████  ██░ ██ ▓█████  ██▓     ██▓
    ▓█████▄  ██  ▓██▒ ██▄█▒  ██  ▓██▒ ██ ▀█   █ ▓██▒▀█▀ ██▒▓██▒▒██    ▒    ▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒
    ▒██▒ ▄██▓██  ▒██░▓███▄░ ▓██  ▒██░▓██  ▀█ ██▒▓██    ▓██░▒██▒░ ▓██▄      ░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░
    ▒██░█▀  ▓▓█  ░██░▓██ █▄ ▓▓█  ░██░▓██▒  ▐▌██▒▒██    ▒██ ░██░  ▒   ██▒     ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░
    ░▓█  ▀█▓▒▒█████▓ ▒██▒ █▄▒▒█████▓ ▒██░   ▓██░▒██▒   ░██▒░██░▒██████▒▒   ▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒
    ░▒▓███▀▒░▒▓▒ ▒ ▒ ▒ ▒▒ ▓▒░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒ ░ ▒░   ░  ░░▓  ▒ ▒▓▒ ▒ ░   ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░
    ▒░▒   ░ ░░▒░ ░ ░ ░ ░▒ ▒░░░▒░ ░ ░ ░ ░░   ░ ▒░░  ░      ░ ▒ ░░ ░▒  ░ ░   ░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░
     ░    ░  ░░░ ░ ░ ░ ░░ ░  ░░░ ░ ░    ░   ░ ░ ░      ░    ▒ ░░  ░  ░     ░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░
     ░         ░     ░  ░      ░              ░        ░    ░        ░           ░   ░  ░  ░   ░  ░    ░  ░    ░  ░
          ░
```

============================================

## Features

- **Standard Shell Commands**: Execute standard Linux commands.
- **Built-in Commands**:
  - `cd`: Change directory.
  - `help`: Display help information.
  - `exit`: Exit the shell.
  - `chat`: Enter an interactive AI chat mode.
- **AI Integration**: Chat with Gemini directly from the terminal.
- **Line Editing**: Supports command history and line editing via `libreadline`.

## Prerequisites

Before building the project, ensure you have the following installed:

- **GCC**: GNU Compiler Collection.
- **Make**: Build automation tool.
- **libreadline**: Library for command line editing.
  - Debian/Ubuntu: `sudo apt-get install libreadline-dev`
  - Fedora/RHEL: `sudo dnf install readline-devel`
  - macOS: `brew install readline`
- **curl**: Command line tool for transferring data (required for AI chat).

## Installation

1.  Clone the repository (if applicable) or navigate to the source directory.
2.  Build the project using `make`:

    ```bash
    make
    ```

3.  This will create an executable named `myshell`.

## Usage

Start the shell by running the executable:

```bash
./myshell
```

### AI Chat Configuration

To use the `chat` command, you must set the `GEMINI_API_KEY` environment variable.

1.  Get an API key from [Google AI Studio](https://aistudio.google.com/).
2.  Export the key in your terminal:

    ```bash
    export GEMINI_API_KEY="your_api_key_here"
    ```

3.  Inside `myshell`, type `chat` to enter AI chat mode.

## Cleaning Up

To remove build artifacts:

```bash
make clean
```

---
[Check out the video](https://1drv.ms/v/c/4ad23e53cfa94e72/IQBAlBFF1IoERYYRpxC0LEHoAT5mWwzCyF0iJdhwjmkA6Xk?e=bW2wGU)

