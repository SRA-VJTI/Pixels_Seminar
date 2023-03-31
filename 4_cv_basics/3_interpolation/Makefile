# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Include directories
INCLUDES = -I./include -I/usr/local/include/opencv4

# Library directories
LDFLAGS = -L/usr/local/lib

# Libraries
LIBS = -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

# Source files
SRCS = ./src/main.cpp ./src/interpolation.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Target binary
TARGET = ./bin/Interpolation

# Rules
build: $(TARGET)
	@echo "Building..."

$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

.cpp.o:
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run:
	@echo "Running..."
	@./bin/Interpolation

clean:
	@echo "Cleaning..."
	@rm -f $(OBJS) $(TARGET)