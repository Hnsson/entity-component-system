CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude

SRC_DIR = src
EXAMPLES_DIR = examples
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
EXAMPLES = $(wildcard $(EXAMPLES_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: ecs_library main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

ecs_library: $(OBJS)
	ar rcs $(BUILD_DIR)/ecs_library.a $(OBJS)

main: ecs_library $(EXAMPLES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(EXAMPLES) $(BUILD_DIR)/ecs_library.a -o $(BUILD_DIR)/main

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean ecs_library main

