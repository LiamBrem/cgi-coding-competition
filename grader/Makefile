CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = grader
SRC_DIR = src
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/grader.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
