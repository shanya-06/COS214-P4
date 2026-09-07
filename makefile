# make -> build target
# ./taskforge -> run it
# make debug -> extra debug & sanitation

CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g
SANFLAGS := -fsanitize=address,undefined
TARGET   := taskforge

SRCS := $(wildcard *.cpp) #detects all cpp files automatically
OBJS := $(SRCS:.cpp=.o)
 
.PHONY: all debug clean
 
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
debug: CXXFLAGS += $(SANFLAGS)
debug: clean $(TARGET)

valgrind:
	g++ -std=c++11 -g *.cpp -o taskforge
	valgrind --leak-check=full ./taskforge
 
clean:
	rm -f $(OBJS) $(TARGET)
