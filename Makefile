# Compiler settings
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Directories
SRC_DIR = src
DATA_STRUCTURES_DIR = data_structures/arrays
BUILD_DIR = build

INCLUDE_DIR = $(DATA_STRUCTURES_DIR)

# Files
MAIN_SRC = $(SRC_DIR)/main.cpp
ARRAY_STATIC_HEADER = $(DATA_STRUCTURES_DIR)/array_static.h

TARGET = $(BUILD_DIR)/program

OBJ = $(BUILD_DIR)/main.o

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile the main.cpp into object file
$(BUILD_DIR)/main.o: $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(MAIN_SRC) -o $(BUILD_DIR)/main.o

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the program after building
run: $(TARGET)
	./$(TARGET)
