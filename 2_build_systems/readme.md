# Build Systems

In this page, you'll find notes on compilers, build systems, and GNU Make build system. It also contains the readme for the Makefile in the Root of the pixels folder.

## Table of contents

- [Build Systems](#build-systems)
	- [Table of contents](#table-of-contents)
	- [Makefile for Pixels](#makefile-for-pixels)
		- [How to use](#how-to-use)
			- [Install OpenCV](#install-opencv)
			- [Building](#building)
			- [Run](#run)
			- [Variables](#variables)
			- [Note](#note)
	- [Build Systems](#build-systems-1)
		- [Compilers](#compilers)
			- [What is a compiler?](#what-is-a-compiler)
			- [Compiler Directives](#compiler-directives)
			- [Different stages of compilation](#different-stages-of-compilation)
			- [Different types of files during compilation](#different-types-of-files-during-compilation)
		- [Build Systems](#build-systems-2)
			- [What is a build system ?](#what-is-a-build-system-)
			- [Why do we need build systems ?](#why-do-we-need-build-systems-)
			- [GNU Make Build System](#gnu-make-build-system)
				- [Syntax of Makefile](#syntax-of-makefile)
				- [Example 1](#example-1)
				- [Variables in Makefile](#variables-in-makefile)
				- [Example 2](#example-2)
				- [Automatic Variables and Wildcards in Makefile](#automatic-variables-and-wildcards-in-makefile)
					- [Automatic Variables](#automatic-variables)
					- [The `*` wildcard](#the--wildcard)
					- [The `%` wildcard](#the--wildcard-1)
					- [Example 3](#example-3)
				- [Commands and execution](#commands-and-execution)

## Makefile for Pixels

This is a Makefile to build and run the Pixels code. The Makefile has the following features:

- It can check if OpenCV is installed on the system and install it if it is not.
- It can build the project and create an executable file in the specified subfolder.
- It can clean all build files in the specified subfolder or all subfolders.
- It can run the executable file in the specified subfolder.

### How to use

#### Install OpenCV

Before using this Makefile, you need to install OpenCV. You can install OpenCV by running the `make install` command.

#### Building

To build any subfolder, run the following command:

```bash
make build FOLDER=<subfolder>
```

Replace `<subfolder>` with the name of the subfolder that contains the example code. The command will create an executable file in the `bin` folder.

By this command, the makefile with run a command similar to the following:

```bash
g++ -o bin/<subfolder> <subfolder>/<subfolder>.cpp -I<subfolder>/build `pkg-config opencv4 --cflags --libs`
```
All files are first copied to the `<subfolder>/build` folder, while replacing all in-file variables with their values. Then, the command is run. Binaries are stored in the `bin` folder.

If you want to clean all build files in all subfolders, run the command without the FOLDER argument:

```bash
make clean
```
To clean a specific subfolder's build files, run the following command:

```bash
make clean FOLDER=<subfolder>
```

#### Run

To run any subfolder's compiled code, run the following command:

```bash
make run FOLDER=<subfolder>
```

Replace `<subfolder>` with the name of the subfolder that contains the project. The command will run the executable file in the `bin` folder.

#### Variables

The following variables are used in the Makefile:

- `CC`: The compiler to use. The default value is `g++`.
- `CFLAGS`: The compiler flags. The default value is empty.
- `LDFLAGS`: The linker flags to link with the OpenCV libraries. The default value is `pkg-config opencv4 --cflags --libs`.
- `BIN_DIR`: The directory to store the executable file. The default value is `bin`.
- `PROJECT_SOURCE_DIR`: This is a variable that is used to store the path to the makefile's directory. It is mainly used to refer to assets which can be used in the openCV examples. Any asset can be accessed by using the following path: `PROJECT_SOURCE_DIR/assets/<asset>`.

#### Note

- The Makefile assumes that the subfolder contains a file with the same name as the subfolder, with the extension .cpp.
- The Makefile assumes that the header files are in the same directory as the source files.

## Build Systems

### Compilers

#### What is a compiler?

A compiler is a special program that translates a programming language's source code into machine code, bytecode or another programming language. The source code is typically written in a high-level, human-readable language such as C/C++.

#### Compiler Directives 

Compiler directives refer to statement written in the source code of a program that lets the programmer instruct the compiler to perform a specific operation within the compilation phase itself.

For example, the ```#include``` directive incorporates the contents of a header file to the compilation. Similarly, The ```#define``` directive is used to define a macro.

#### Different stages of compilation

<p align="center">
  <img src="../assets/images/Compilation_Stages.png" width="800" />
</p>

The compilation process transforms a human-readable code into a machine-readable format. For a programming language, it happens before a program starts executing to check the syntax and semantics of the code. The compilation process involves four steps: pre-processing, compiling, assembling, and linking then, we run the obtained executable file to get an output on the screen.

1) Pre-Processing : Common tasks accomplished by preprocessing are macro substitution, testing for conditional compilation directives, and file inclusion.

2) Compiling : The code which is expanded by the preprocessor is passed to the compiler. The compiler converts this code into assembly code. Or we can say that the C compiler converts the pre-processed code into assembly code.

3) Assembling : The assembly code is converted into object code by using an assembler. The name of the object file generated by the assembler is the same as the source file. 

4) Linking : The main working of the linker is to combine the object code of library files with the object code of our program.

#### Different types of files during compilation

During the stages of compilation, there are several types of files involved.

* Source(.c):
These files contain function definitions, and the entire program logics. These files are human readable and by convention their names ends with ```.c```, ```.cpp```, ```.py```, etc.

* Assembly(.s):
Assembly Language mainly consists of mnemonic processor instructions or data and other statements or instructions. 

	Flag : -S 

	eg. ```gcc -S foo.c```
	
	This command will generate ```foo.s``` as output.

* Object(.o):
These files are produced as the output of the compiler. They consist of function definitions in binary form, but they are not executable by themselves and by convention their names end with ```.o```. 

	Flag : -c
	
	eg. ```gcc -c foo.c```
	
	This command will generate ```foo.o``` as output.

### Build Systems

#### What is a build system ?

All build systems have a straightforward purpose: they transform the source code written by humans into executable binaries that can be read by machines. 

Build systems aren't just for human-authored code; they also allow machines to create builds automatically, whether for testing or for releases to production. In an organization with thousands of engineers, it's common that most builds are triggered automatically rather than directly by engineers.

#### Why do we need build systems ?

The need for a build system might not be immediately obvious. As long as all the source code is in the same directory, a command like this works fine:

```c
gcc main.c
```
This instructs the compiler to take convert main.c into a binary class file. In the simplest case, this is we you need.

However, as soon as code expands, the complications begin. Our compiler has no way of finding code stored in other parts of the filesystem (perhaps a library shared by several projects). 

Large systems often involve different pieces written in a variety of programming languages with several dependencies among those pieces, meaning no compiler for a single language can possibly build the entire system. 

The compiler also doesn’t know anything about how to handle external dependencies. Without a build system, it's difficult to maintain the updates, versions, and source of these external dependencies.

This is why we need build systems.

#### GNU Make Build System

Makefiles are useful for determining which parts of a large program need recompilation. They are commonly used to compile C and C++ files but other languages have similar tools. Make can also be used to run a series of instructions when specific files change.

##### Syntax of Makefile

Makefile consists of a set of rules.

```makefile
target: prerequisites
	command_1
	command_2
	command_3
```

- **Targets** are file names, which are separated by spaces.
- **Commands** are a series of specific steps that need to be executed in order to create the target files. These commands must start with a tab character.
- Each target may have one or more **prerequisites** that need to exist before the target can be built.
- Prerequisites are also files, and they must be created before the target file can be generated.

##### Example 1

Let's create a very simple Makefile. First, create an `example.c` file:

```c
int main() {return 0;}
```

Then, let's create our first `Makefile`. Create the file (`touch Makefile`) and add a target `hello`.

```makefile
hello: example.c
	gcc example.c -o hello
```

Now, when we run `make` in the terminal, we see that a new file is created, called `hello`. This file is the compiled executable of `example.c`, which we can execute. If we run `make` again, nothing happens, and it says `make: 'example.c' is up to date`.

Let's make a small change in `example.c`, and observe the response of Make.

```c
#include <stdio.h>
int main() { printf("Hello, world!"); return 0; }
```

Now, when we run `make`, we can observe that the file is recompiled. This is because `example.c` is a dependency of `hello`, therefore when the dependency is changed the target is built again.

How does make do this? It uses the file-system timestamps to determine if something has changed. If the dependencies of a target are changed, the target is regenerated.

##### Variables in Makefile

Makefile supports variables, but only strings.

```makefile
file_name = example.c
executable_name = hello

$(executable_name): $(file_name)
	gcc $(file_name) -o $(executable_name)
```

Here, the target name can be modified as per our requirement.

We must remember that even though everything is a string, single and double quotes have no meaning to Make.

```makefile
a := one two # a is assigned to the string "one two"
b := 'one two' # Not recommended. b is assigned to the string "'one two'"
```

We can reference variables using either `$()` or `${}`.

##### Example 2

Let’s try something more. Create two files `greeting.c` and `hello.c`.

```c
//hello.c
#include <stdio.h>
int main() { printf("Hello, world!"); return 0; }
```

```c
//greeting.c
#include <stdio.h>
int main() { printf("Welcome!"); return 0; }
```

Let’s create a Makefile that shall compile both of these files.

```makefile
hello: hello.c
	gcc hello.c -o hello
greeting: greeting.c
	gcc greeting.c -o greeting
```

As seen before, running either `make hello` or `make greeting` will compile the `hello.c` or the `greeting.c`.

> What do you think happens when simply `make` is run?
> 

But, what if the requirement arises to run both of the targets at once? We can create an `all` target, that will run both the rules.

```makefile
all: hello greeting

hello: hello.c
	gcc hello.c -o hello
greeting: greeting.c
	gcc greeting.c -o greeting
```

##### Automatic Variables and Wildcards in Makefile

###### Automatic Variables

Here are some automatic variables which can be used in Makefile:

- `$@` returns the filename representing the target.
- `$<` returns the filename of the first prerequisite.
- `$^` returns the names of all the prerequisites, separated by spaces
- `$?` returns the names of only the prerequisites that are newer than the target, separated by spaces.

###### The `*` wildcard

The `*` wildcard searches your file-system for matching filenames. In the previous example, we can list out all the C files with it’s help

```makefile
print: $(wildcard *.c)
	ls -la  $^
```

###### The `%` wildcard

The `%` wildcard is used to match any string. It is useful when our files follow a certain pattern. The `%` character matches any string, and that string is used as a variable in the rule definition.

For example, let's say we have several source files with the extension `.c`, and we want to compile them into object files with the extension `.o`. We could use the `%` wildcard to match any file name and then substitute the `.c` extension with `.o` to create the object file name.

```makefile
%.o: %.c
	gcc -c $< -o $@
```

This rule tells make that any file ending in `.o` can be created by compiling the corresponding `.c` file. The `$<` automatic variable is used to get the name of the first prerequisite, which in this case is the `.c` file. The `$@` variable is used to get the name of the target, which is the `.o` file.

###### Example 3

Let's say we have three source files called `file1.c`, `file2.c`, and `file3.c`. We want to create three corresponding object files called `file1.o`, `file2.o`, and `file3.o`. We can use the `%` wildcard to match the file names and create a rule that compiles any `.c` file into a corresponding `.o` file.

```makefile
%.o: %.c
	gcc -c $< -o $@

all: file1.o file2.o file3.o
```

This rule tells make that any file ending in `.o` can be created by compiling the corresponding `.c` file. The `$<` automatic variable is used to get the name of the first prerequisite, which in this case is the `.c` file. The `$@` variable is used to get the name of the target, which is the `.o` file.

When we run `make all`, it will compile all three source files into object files using the same rule.

##### Commands and execution

Makefile executes all commands under the target. The commands under the target are executed in the order they appear in the Makefile. 

The printing of each command at execution can be stopped by the use of `@` .

```makefile
all: 
	@echo "This make line will not be printed"
	echo "But this will"
```

Each command in a target is run in a new shell. To run commands in the same shell, one can either use semicolons or forward slashes.

```makefile
all:
	cd ..
	echo `pwd`
	#the above command are run in seperate shells.
	cd ..; echo `pwd`;
	#these commands are run in the same shell.
	cd ..; \
	echo `pwd`
	#these commands are run in the same shell as well.
```

---
