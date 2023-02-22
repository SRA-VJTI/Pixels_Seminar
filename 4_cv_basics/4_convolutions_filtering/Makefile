CC = g++

PROJECT = Convolution_Filtering
SRC = main.cpp convolution.cpp

CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4) -Iinclude/
LIBS = $(shell pkg-config --libs opencv4)

$(PROJECT) : $(SRC)
	$(CC) $(SRC) -o $(PROJECT) $(CFLAGS) $(LIBS)