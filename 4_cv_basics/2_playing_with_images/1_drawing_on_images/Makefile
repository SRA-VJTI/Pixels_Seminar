GCC = "g++"

PROJECT = drawing_on_images
SRC = drawing_on_images.cpp

CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

$(PROJECT) : $(SRC)
	$(GCC) $(SRC) -o $(PROJECT) $(CFLAGS) $(LIBS) 