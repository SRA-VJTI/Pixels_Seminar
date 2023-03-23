# Makefile for Pixels

This is a Makefile to build and run the Pixels code. The Makefile has the following features:

- It can check if OpenCV is installed on the system and install it if it is not.
- It can build the project and create an executable file in the specified subfolder.
- It can clean all build files in the specified subfolder or all subfolders.
- It can run the executable file in the specified subfolder.

## How to use

### Install OpenCV

Before using this Makefile, you need to install OpenCV. You can install OpenCV by running the make install command.
Build the project

## Building

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

### Run

To run any subfolder's compiled code, run the following command:

```bash
make run FOLDER=<subfolder>
```

Replace `<subfolder>` with the name of the subfolder that contains the project. The command will run the executable file in the `bin` folder.

### Variables

The following variables are used in the Makefile:

- `CC`: The compiler to use. The default value is `g++`.
- `CFLAGS`: The compiler flags. The default value is empty.
- `LDFLAGS`: The linker flags to link with the OpenCV libraries. The default value is `pkg-config opencv4 --cflags --libs`.
- `BIN_DIR`: The directory to store the executable file. The default value is `bin`.
- `PROJECT_SOURCE_DIR`: This is a variable that is used to store the path to the makefile's directory. It is mainly used to refer to assets which can be used in the openCV examples. Any asset can be accessed by using the following path: `PROJECT_SOURCE_DIR/assets/<asset>`.

#### Note

- The Makefile assumes that the subfolder contains a file with the same name as the subfolder, with the extension .cpp.
- The Makefile assumes that the header files are in the same directory as the source files.