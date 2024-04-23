CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SRCDIR = src
BINDIR = bin

# List all your source files here
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Derive object file names from source file names
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Name of your executable
TARGET = my_program

# Main target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(BINDIR)/*.o $(TARGET)