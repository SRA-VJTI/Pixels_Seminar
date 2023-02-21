# Makefile for the entire project

# Variables
CC = g++
CFLAGS = #-Wall -std=c++11 -shared
# LDFLAGS = ` -lm -lstdc++ -lsqlite3 pkg-config opencv4 --cflags --libs`
LDFLAGS = `pkg-config opencv4 --cflags --libs` -lsqlite3
BIN_DIR = bin
#command to get the OS
UNAME_S := $(shell uname -r)
#check if OpenCV is installed(check for not found error) print true if not found, false if found
OPENCV_INSTALLED := $(shell pkg-config --exists opencv4 && echo true || echo false | awk '{print $1}')


# the command make build FOLDER=<subfolder> should build the executable in the subfolder
# the compile command should compile the <subfolder>.cpp file and link it with the OpenCV libraries, including the header files in the subfolder
ifeq ($(FOLDER),)
build:
	@echo "Folder is not set"
else
build:
	@echo "Building..."
	@echo $(FOLDER)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(FOLDER)/build
	@echo $(shell pwd) 
	@cp $(FOLDER)/*.cpp $(FOLDER)/build && cp $(FOLDER)/*.hpp $(FOLDER)/build 
	@find $(FOLDER)/build -name "*.cpp" -type f -exec sed -i 's@PROJECT_SOURCE_DIR@../..@g' {} \;
	@find $(FOLDER)/build -name "*.hpp" -type f -exec sed -i 's@PROJECT_SOURCE_DIR@../..@g' {} \;
	@$(CC) $(CFLAGS) $(FOLDER)/build/$(notdir $(shell basename $(FOLDER))).cpp -o $(BIN_DIR)/$(notdir $(shell basename $(FOLDER))) -I $(FOLDER)/build $(LDFLAGS)
endif
	

# the command make clean FOLDER=<subfolder> should remove all build files in the subfolder
# if folder is not set, clean all build files all subfolders
ifeq ($(FOLDER),)
clean:
	@echo "Cleaning..."
	@rm -rf **/build && rm -rf */*/build
	@rm -rf $(BIN_DIR)
else
clean:
	@echo "Cleaning..."
	@rm -rf $(FOLDER)/build
	@rm -rf $(BIN_DIR)/$(notdir $(shell basename $(FOLDER)))
endif

# the command make run FOLDER=<subfolder> should run the executable in the subfolder
ifeq ($(FOLDER),)
run:
	$(error FOLDER is not set)
else
run:
	@echo "Running..."
	@./$(BIN_DIR)/$(notdir $(shell basename $(FOLDER)))
endif