CC = gcc
CXX = g++
CFLAGS = -g
CXXFLAGS = -g
SRC_C = $(wildcard *.c)
SRC_CPP = $(wildcard *.cpp)
OBJ_C = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)
EXEC = eshell

$(EXEC): $(OBJ_C) $(OBJ_CPP)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_C) $(OBJ_CPP) $(EXEC)
