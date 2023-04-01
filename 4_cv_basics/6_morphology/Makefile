# Specifying which compiler to use
CC = g++							

# Defining the name of the object that will be created after using make
PROJECT = morphology		

# Here Include specifies which directories can be added in the include path of the main.cpp
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -Iinclude/		
# What libraries to be imported here it is opencv
LIBS = $(shell pkg-config --libs opencv4) 

# Similar to how we used to link ad make object files in the terminal
# the command make build <subfolder name> should build the executable 
link = src/morphology.cpp
.PHONY: build
build:
	@echo "Building..."
	@$(CC) $(filter-out $@,$(MAKECMDGOALS))/main.cpp $(link) -o _$(filter-out $@,$(MAKECMDGOALS)) $(CFLAGS) $(LIBS)
%::
	@true
# if folder is not set, clean all build files all subfolders
.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf _$(filter-out $@,$(MAKECMDGOALS))