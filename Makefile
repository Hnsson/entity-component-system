CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

MAIN = $(SRC_DIR)/main.cpp
TEST_SRC = $(TEST_DIR)/ecs_tests.cpp
MAIN_OBJ = $(BUILD_DIR)/main.o
TEST_OBJ = $(BUILD_DIR)/tests.o
LIB = $(BUILD_DIR)/libecs.a
EXEC = $(BUILD_DIR)/main
TEST_EXEC = $(BUILD_DIR)/tests

all: $(EXEC)

$(LIB): | $(BUILD_DIR)
	ar rcs $(LIB)

$(MAIN_OBJ): $(MAIN) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(MAIN_OBJ) $(LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_EXEC): $(TEST_OBJ) $(LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean test

