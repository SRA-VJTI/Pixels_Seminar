GCC = "g++"

PROJECT = Pixels_Seminar
SRC = main.cpp

CFLAGS = -std=c++11 $(shell pkg-config --cflags opencv4)
LIBS = $(shell pkg-config --libs opencv4)

$(PROJECT) : $(SRC)
	$(GCC) $(SRC) -o $(PROJECT) $(CFLAGS) $(LIBS) 