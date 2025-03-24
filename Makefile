CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -pedantic
SRC_DIR = src
HEADER_DIR = header

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

EXEC = main

all: $(EXEC)

$(EXEC): main.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) main.o $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -I$(HEADER_DIR) -c main.cpp

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o *.o $(EXEC)
