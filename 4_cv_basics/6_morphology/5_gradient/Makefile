# Variables
CC = g++
CFLAGS = #-Wall -std=c++11 -shared
# LDFLAGS = ` -lm -lstdc++ -lsqlite3 pkg-config opencv4 --cflags --libs`
LDFLAGS = `pkg-config opencv4 --cflags --libs`
BIN_DIR = bin
FOLDER = .
FILE=5_gradient.cpp
FILE1=../src/morphology.cpp
H1=../include/morphology.hpp

# the command make build FILE=<FILENAME> should build the executable in the subfolder
.PHONY: build
ifeq ($(FILE),)
build:
	$(error "FILE is not set")
else
build:
	@echo "Building..."
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(FOLDER)/build
	@cp $(FOLDER)/*.cpp $(FOLDER)/build 
	@find $(FOLDER)/build -name "*.cpp" -type f -exec sed -i 's@PROJECT_SOURCE_DIR@$(shell pwd)@g' {} \;
	@$(CC) $(CFLAGS) $(FILE) $(H1) $(FILE1) -o $(BIN_DIR)/$(basename $(FILE)) -I $(FOLDER)/build $(LDFLAGS)
endif	

# the command make clean FOLDER=<subfolder> should remove all build files in the subfolder
# if folder is not set, clean all build files all subfolders
.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf $(FOLDER)/build
	@rm -rf $(BIN_DIR)

# the command make run FOLDER=<subfolder> should run the executable in the subfolder
ifeq ($(FILE),)
FILE=5_gradient.cpp
run:
	$(error FILE is not set)
else
run:
	@echo "Running..."
	@./$(BIN_DIR)/$(basename $(FILE)) ../assets/SRA_Logo_WHITE.png
endif
