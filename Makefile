CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build

MAIN = $(SRC_DIR)/main.cpp
MAIN_OBJ = $(BUILD_DIR)/main.o
LIB = $(BUILD_DIR)/libecs.a
EXEC = $(BUILD_DIR)/main

all: $(EXEC)

$(LIB): | $(BUILD_DIR)
	ar rcs $(LIB)

$(MAIN_OBJ): $(MAIN) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(MAIN_OBJ) $(LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

