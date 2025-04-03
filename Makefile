# Compiler settings
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Directories
SRC_DIR = src
DATA_STRUCTURES_DIR = data_structures/arrays
LINKED_LISTS_DIR = data_structures/linkedlists
SEARCHING_DIR = algorithms/searching
SORTING_DIR = algorithms/sorting
BUILD_DIR = build

# Include directories
INCLUDE_DIR = $(DATA_STRUCTURES_DIR) $(LINKED_LISTS_DIR) $(SEARCHING_DIR) $(SORTING_DIR)

# Files
MAIN_SRC = $(SRC_DIR)/main.cpp
ARRAY_STATIC_HEADER = $(DATA_STRUCTURES_DIR)/array_static.h
ARRAY_DYNAMIC_HEADER = $(DATA_STRUCTURES_DIR)/array_dynamic.h
SINGLY_LINKED_LIST_HEADER = $(LINKED_LISTS_DIR)/singly_linkedlist.h
BINARY_SEARCH_HEADER = $(SEARCHING_DIR)/binarysearch.h
MERGE_SORT_HEADER = $(SORTING_DIR)/mergesort.h
BUBBLE_SORT_HEADER = $(SORTING_DIR)/bubblesort.h

TARGET = $(BUILD_DIR)/program

OBJ = $(BUILD_DIR)/main.o

# Default target
all: $(TARGET)

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files to create the executable
$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile the main.cpp into object file
$(BUILD_DIR)/main.o: $(MAIN_SRC) $(ARRAY_STATIC_HEADER) $(ARRAY_DYNAMIC_HEADER) $(SINGLY_LINKED_LIST_HEADER) $(BINARY_SEARCH_HEADER) $(MERGE_SORT_HEADER) | $(BUILD_DIR)
	@echo "Include directories: $(INCLUDE_DIR)"
	$(CXX) $(CXXFLAGS) $(foreach dir,$(INCLUDE_DIR),-I$(dir)) -c $(MAIN_SRC) -o $(BUILD_DIR)/main.o

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the program after building
run: $(TARGET)
	./$(TARGET)
