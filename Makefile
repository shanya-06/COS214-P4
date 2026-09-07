CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# List all your source files here
SRCS = main.cpp SongItem.cpp State.cpp

# Converts the .cpp filenames to .o (object) filenames
OBJS = $(SRCS:.cpp=.o)

# The name of the final executable
TARGET = TaskForge

# Default target when you just run 'make'
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
