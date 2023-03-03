CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
LIBS = -lSDL2 -lSDL2_image

SRCS = image_storing_formats.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = image

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
