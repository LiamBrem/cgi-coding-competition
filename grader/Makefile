CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = grader
SRC_DIR = src
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/grader.cpp
OBJS = $(SRCS:.cpp=.o)

# Cross-compilation for Windows
MINGW_CXX = x86_64-w64-mingw32-g++
MINGW_TARGET = grader.exe
MINGW_OBJS = $(SRCS:.cpp=.win.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Windows cross-compilation targets
windows: $(MINGW_TARGET)

$(MINGW_TARGET): $(MINGW_OBJS)
	$(MINGW_CXX) $(CXXFLAGS) -o $(MINGW_TARGET) $(MINGW_OBJS) -static-libgcc -static-libstdc++

%.win.o: %.cpp
	$(MINGW_CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MINGW_OBJS) $(TARGET) $(MINGW_TARGET)

.PHONY: all windows clean
