# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Executable name
TARGET = lab13

# Source file
SRCS = lab13.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
