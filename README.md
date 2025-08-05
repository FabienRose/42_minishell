# Minishell

A lightweight shell implementation written in C that provides a command-line interface with built-in commands, environment variable management, and basic shell features like pipes and redirections.

## Features

- **Built-in Commands**: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Command Execution**: Execute external programs from PATH
- **Environment Management**: Full environment variable support with `getenv()` compatibility
- **Redirections**: Input (`<`) and output (`>`, `>>`) redirections
- **Pipes**: Command chaining with `|`
- **Logical Operators**: `&&` and `||` for conditional execution
- **Signal Handling**: Proper handling of Ctrl+C and Ctrl+D
- **Command Groups**: Support for parentheses `()` for command grouping
- **Wildcards**: Basic wildcard expansion with `*`

## Installation

Clone the repository and build from source:
```bash
git clone https://github.com/FabienRose/42_minishell.git
cd minishell
make
```

## Usage

Start the shell and use it like any other shell:

```bash
# Start minishell
./minishell

# Use built-in commands
echo "Hello World"
pwd
cd /tmp
export TEST=value
env

# Execute external programs
ls -la
cat file.txt

# Use pipes and redirections
ls | grep "\.c$" > c_files.txt
echo "test" >> output.txt

# Command chaining
cd /tmp && ls -la || echo "Failed to change directory"

# Command groups
(cd /tmp && ls) | wc -l
```

## Built-in Commands

- `echo [-n] [string...]` - Print arguments with optional newline suppression
- `cd [directory]` - Change current directory
- `pwd` - Print working directory
- `export [name=value]` - Set environment variables
- `unset [name]` - Remove environment variables
- `env` - Print all environment variables
- `exit [status]` - Exit shell with optional status code

## Project Structure

```
minishell/
├── shell/          # Core shell functionality
├── builtins/       # Built-in command implementations
├── exec/           # Command execution and process management
├── env/            # Environment variable handling
├── groups/         # Command parsing and grouping
├── token/          # Tokenization and lexical analysis
├── prompt/         # Prompt display and input handling
├── io/             # Input/output redirection
├── utils/          # Utility functions
└── libft/          # Custom library functions
```

## License

This project is part of the 42 curriculum and follows the 42 coding standards. 
