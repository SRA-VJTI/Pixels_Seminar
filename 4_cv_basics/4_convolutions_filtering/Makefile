CC = g++							# Specifying which compiler to use

PROJECT = Convolution_Filtering		# Defining the name of the object that will be created after using make
SRC = main.cpp convolution.cpp		# Linking the Two Files - > Function of convolution.cpp is accessed by main.cpp through header file

CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -Iinclude/		# Here Include specifies which directories can be added in the include path of the main.cpp
LIBS = $(shell pkg-config --libs opencv4)	# What libraries to be imported here it is opencv

$(PROJECT) : $(SRC)							# Similar to how we used to link and make object files in the terminal
	$(CC) $(SRC) -o $(PROJECT) $(CFLAGS) $(LIBS)	