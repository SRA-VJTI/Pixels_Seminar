## Compilers

### What is a compiler?

A compiler is a special program that translates a programming language's source code into machine code, bytecode or another programming language. The source code is typically written in a high-level, human-readable language such as C/C++.

### Compiler Directives 

Compiler directives refer to statement written in the source code of a program that lets the programmer instruct the compiler to perform a specific operation within the compilation phase itself.

For example, the ```#include``` directive incorporates the contents of a header file to the compilation. Similarly, The ```#define``` directive is used to define a macro.

### Different types of files during compilation

<p align="center">
  <img src="../../assets/images/Compilation_Stages.png" width="800" />
</p>

The compilation process transforms a human-readable code into a machine-readable format. For a programming language, it happens before a program starts executing to check the syntax and semantics of the code. The compilation process involves four steps: pre-processing, compiling, assembling, and linking then, we run the obtained executable file to get an output on the screen.

* Source(.c):
These files contain function definitions, and the entire program logics, these files are human readable and by convention their names ending with . c

* Assembly(.s):
Assembly Language mainly consists of mnemonic processor instructions or data and other statements or instructions.Flag -S eg. gcc -S foo.c

* Object(.o):
These files are produced as the output of the compiler. They consist of function definitions in binary form, but they are not executable by themselves and by convention their names end with .o.Flag -o eg. gcc -o foo.c

## Build Systems

### What is a build system ?

All build systems have a straightforward purpose: they transform the source code written by humans into executable binaries that can be read by machines. 

Build systems aren't just for human-authored code; they also allow machines to create builds automatically, whether for testing or for releases to production. In an organization with thousands of engineers, it's common that most builds are triggered automatically rather than directly by engineers.

### Why do I need build systems ?

The need for a build system might not be immediately obvious We can invoke tools like gcc directly from the command line, or the equivalent in an integrated development environment (IDE). As long as all the source code is in the same directory, a command like this works fine:

```c
gcc main.c
```
This instructs the compiler to take convert main.c into a binary class file. In the simplest case, this is we you need.

However, as soon as code expands, the complications begin. Our compiler has no way of finding code stored in other parts of the filesystem (perhaps a library shared by several projects). It also only knows how to build the code. 

Large systems often involve different pieces written in a variety of programming languages with webs of dependencies among those pieces, meaning no compiler for a single language can possibly build the entire system. Thus, there are multiple dependencies and without a build system, one must evaluate what the code depends on and build those pieces in the proper orde
The compiler also doesn’t know anything about how to handle external dependencies. Without a build system, you could manage this by downloading the dependency from the internet, sticking it in a lib folder on the hard drive, and configuring the compiler to read libraries from that directory. But over time, it's difficult to maintain the updates, versions, and source of these external dependencies.

This is why we need build systems.