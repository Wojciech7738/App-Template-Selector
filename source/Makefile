# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
DEPFLAGS = -MP -MD
OPT = -O0
# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINARY = main

# Source files
# MAINFILE = $(SRCDIR)/main.cpp
SRCS = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/**/*.cpp)
# INCS = $(foreach D, $(wildcard $(INCDIR)/**/*.h), -I$(D))
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Create the 'obj' directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Linking step
$(BINARY): $(OBJS)
	$(CXX) $^ -o $@

# Compiling step
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) $(DEPFLAGS) $(OPT) -c -o $@ $<

# Include dependency files
-include $(OBJS:.o=.d)

.PHONY: all clean

all: $(OBJDIR) $(BINARY)

clean:
	rm -r $(OBJDIR)
	rm -f $(BINARY)

