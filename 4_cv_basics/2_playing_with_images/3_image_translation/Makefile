GCC = "g++"

PROJECT = image_translation
SRC = image_translation.cpp

CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

$(PROJECT) : $(SRC)
	$(GCC) $(SRC) -o $(PROJECT) $(CFLAGS) $(LIBS) 