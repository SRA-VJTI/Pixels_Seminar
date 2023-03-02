# Specifying which compiler to use
CC = g++							

# Defining the name of the object that will be created after using make
PROJECT = Convolution_Filtering		
# Linking the Two Files - > Function of convolution.cpp is accessed by main.cpp through header file
SRC = main.cpp convolution.cpp		

# Here Include specifies which directories can be added in the include path of the main.cpp
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -Iinclude/		
# What libraries to be imported here it is opencv
LIBS = $(shell pkg-config --libs opencv4)	

# Similar to how we used to link and make object files in the terminal
$(PROJECT) : $(SRC)					
	$(CC) $(SRC) -o $(PROJECT) $(CFLAGS) $(LIBS)	
	
