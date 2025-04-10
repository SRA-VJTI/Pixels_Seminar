# Specifying which compiler to use
CC = g++

# Defining the name of the object that will be created after using make
PROJECT = image_segmentation

# Include directories and compiler flags
CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -Iinclude/

# Linker flags for OpenCV
LIBS = $(shell pkg-config --libs opencv4)

# Source file for segmentation (grabcut or any other)
link = src/segmentation.cpp

# Build target: run `make build SRC=<FILENAME>` to build the executable
.PHONY: build
build:
ifndef SRC
	$(error "SRC is not set")
endif
ifndef link
	$(error "link is not set")
endif
	@echo "Building..."
	@$(CC) $(SRC) $(link) -o $(PROJECT) $(CFLAGS) $(LIBS)

# Clean target to remove built executable
.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf $(PROJECT)
