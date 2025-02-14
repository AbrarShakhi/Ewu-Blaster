CXX = g++ #Compiler
CXXFLAGS = -std=c++17 -Wall -Wextra # Compiler flags
LDFLAGS = -lX11 -lGL -lpng -lpthread -lstdc++fs  # Libraries to link
TARGET = main # Target executable file
SRCS = main.cpp # Source files

OBJS = $(SRCS:.cpp=.o) # Object files (automatically generated from source files)

# Rule to build the target and run it
run: $(TARGET)
	./$(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: clean run
