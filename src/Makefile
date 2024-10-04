# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -I../headers/ -std=c++11

# Source files
SOURCES = main.cpp LinkedList.cpp Node.cpp

# Output executable
TARGET = p

# Build the target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
