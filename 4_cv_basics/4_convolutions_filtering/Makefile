# Makefile for the entire project

# Variables
CC = g++
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -Iinclude/	
# LDFLAGS = ` -lm -lstdc++ -lsqlite3 pkg-config opencv4 --cflags --libs`
LDFLAGS = `pkg-config opencv4 --cflags --libs`
BIN_DIR = bin
FOLDER = .
SRC = main.cpp 
SRC2= convolution.cpp		
FOL=src

# the command make build FILE=<FILENAME> should build the executable in the subfolder
.PHONY: build
ifeq ($(SRC),)
build:
	$(error "FILE is not set")
else
build:
	@echo "Building..."
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(FOLDER)/build
	@cp main.cpp $(FOLDER)/build 
	@cp $(FOL)/* $(FOLDER)/build 
	@find $(FOLDER)/build -name "*.cpp" -type f -exec sed -i 's@PROJECT_SOURCE_DIR@$(shell pwd)@g' {} \;
	@$(CC) $(CFLAGS) $(FOLDER)/build/$(SRC) $(FOLDER)/build/$(SRC2) -o $(BIN_DIR)/$(basename $(SRC)) -I $(FOLDER)/build $(LDFLAGS)
endif	

# the command make clean FOLDER=<subfolder> should remove all build files in the subfolder
# if folder is not set, clean all build files all subfolders
.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf $(FOLDER)/build
	@rm -rf $(BIN_DIR)

# the command make run FOLDER=<subfolder> should run the executable in the subfolder
ifeq ($(SRC),)
SRC = main.cpp 
run:
	$(error FILE is not set)
else
run:
	@echo "Running..."
	@./$(BIN_DIR)/main
endif
