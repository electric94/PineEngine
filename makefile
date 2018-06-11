TARGET = prog

CC = g++
CFLAGS = -Wall -Iinclude/
CPPFLAGS = -std=c++14
LLIBRARIES = -lGlew -lsdl2 -framework OpenGL

INCLUDE_DIR = ../include
SOURCE_DIR = src
OBJECT_DIR = ../obj
BIN_DIR = ../bin
LIBRARY_DIR = ../lib

SRC = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJ = $(SRC:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/*.o)

#.PHONY: all clean
.PHONY: all

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ $(LLIBRARIES) -o $@

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

#clean:
#	$(RM) $(OBJ)

#all: $(TARGET) clean

#$(TARGET): main.o core_engine.o display.o
#	g++ -o $(TARGET) main.o core_engine.o display.o $(CPPFLAGS)

#main.o: main.cpp src/core_engine.cpp
#	g++ -c main.cpp

#core_engine.o: src/core_engine.cpp display.cpp
#	g++ -c src/core_engine.cpp inc/core_engine.hpp

#display.o: display.cpp
#	g++ -c display.cpp

#clean:
#	rm *.o
