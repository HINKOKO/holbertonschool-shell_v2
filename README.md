<h1 align="center" style="color:#FFFFFF"><strong>Simple Shell - Implemented in C language </strong><h1>

<br>

<p align="center">
  <img src="https://bashlogo.com/img/symbol/jpg/full_colored_light.jpg" />
</p>

<h3 align="right"><em>by Anthony Pizzony</em><h3>

# (Not so) Simple Shell 

## Table of contents


A brief description of what this project does and who it's for

- [Description](#description) 
- [File Structure](#file-structure)
- [Requirements](#requirements)
- [Usage](#usage)
- [Exemple of use](#example-of-use)
- [Authors](#authors)
- [License](#license)

## Description 

A UNIX-Shell is a command-line interpreter or "shell" that provides you a command-line
user interface for Unix-like operating systems.
The Shell is both an interactive and a scripting language.
The first Shell was the "Thompson Shell", written by Ken Thompson at Bell Labs, distributed
from 1971 to 1975.
Ken Thompson developped his Shell version, associated with Dennis Ritchie, in the B programming
language.
After creating B, Ritchie and teammates moved to language C.

## File structure

- [Authors](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/AUTHORS.md) - list of contributors to this project
- [man_1_hsh](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/man_1_hsh) - manual page for the simple_shell (in your terminal, run man ./man_1_hsh)
- [shell.h](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/shell.h) - header program file
- Major builtins functions supported:<br>
        - [check_builtins.c](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/check_builtin.c) - check if user's command matches a builtin <br>
        - [new_exit](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/new_exit.c) - exits the shell <br>
        - [print_env](https://github.com/NehemieMbg/holbertonschool-simple_shell/blob/main/print_env.c) - prints the shell environnement's variable to standard output <br>
        - [_cd](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/_cd.c) - changes the current directory to the one specified, with no parameters, `cd` command takes you home/, 'cd - ' is only supported "once" (one call available, problem with updating environment)
        - [_setenv](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/_setenv.c) - set a new environment variable, WARNING => need fixes for somes cases
        - [_help](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/_help.c) - displays a message, help about functions will come later
- Program running commands: <br>
        - [executor](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/executor.c): execute process expected <br>
        - [exec_path](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/execpath.c): search a command along the PATH <br>
        - [pathfinder](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/pathfinder.c): Look in PATH if command exist <br>
- String Functions: <br>
        - [Parser](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/parser.c): get_args function creates token words with the command entered, free_argsfunction frees the space allocated for the array of args. <br>
        - [wordcount](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/wordcount.c): create tokenized words. <br>
        - [string-helpers](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/string_helpers.c) - Various string functions to handle manipulations of arguments <br>
        - [string-helpers-2](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/string_helpers-2.c) Continuation of [string-helpers](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/string_helpers.c) <br>
- Signal Functions: <br>
        - [handle_signal](https://github.com/HINKOKO/holbertonschool-shell_v2/blob/main/handle_signal.c) - Function to catch the signal SIGINT (Ctrl^C) for not exiting the shell but displays a new line. <br> 

## Requirements

Simple shell project was compiled on `Ubuntu 20.04 LTS` using gcc compiler, with following options <br>

```
gcc -Wall -Werror Wextra -pedantic -std=gnu89
```
## Usage

Clone this repository: <br>
```
git clone git@github.com:HINKOKO/holbertonschool-shell_v2.git
```
Switch inside the directory: 
```
cd holbertonschool-simple_shell
```
Compile all the files using the Makefile (target `all`) :
```
make all
```
You're all good to use the shell either in Interactive mode, to do so enter in your terminal:
```
./hsh
```
Then a prompt will be displayed, and you can enter commands.

The other way is in Non-Interactive mode, by piping the command to executable "hsh";  for example if you want to list files and directory, command ```ls```, call the shell like so:
```
echo "/bin/ls" | ./hsh
```
## Example of use

Take a look at this example of use:

![DuragShell](/screenshots/DURAGSHELL.png)

## Authors

*The following person worked on this project:* <br>

Anthony Pizzoni <br>
&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;- piotr62@live.fr <br>
&nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;- https://github.com/HINKOKO

## License

This C-Simple-Shell is open-source, free to download and use without permissions.



[Back to Summary](#table-of-contents)






