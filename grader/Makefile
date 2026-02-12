CXX ?= clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = grader
BUILD_DIR = build
SRC_DIR = src
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/grader.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Cross-compilation for Windows
MINGW_CXX = x86_64-w64-mingw32-g++
MINGW_TARGET = grader.exe
MINGW_OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.win.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Windows cross-compilation targets
windows: $(MINGW_TARGET)

$(MINGW_TARGET): $(MINGW_OBJS)
	$(MINGW_CXX) $(CXXFLAGS) -o $(MINGW_TARGET) $(MINGW_OBJS) -static

$(BUILD_DIR)/%.win.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(MINGW_CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(MINGW_TARGET)

.PHONY: all windows clean
