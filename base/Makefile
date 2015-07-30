#Generic Makefile for animation projects

TARGET	= gears

#Compilers and flags
CXX		= g++

#Compiler flags
CXXFLAGS	= -g -Wall -Wextra
CXXFLAGS	+= -I/usr/local/include
CXXFLAGS	+= -O0
THREADS		= -std=c++11

LINKER	= g++ -o
#Linking flags
LFLAGS	= -Wall -I. -lm -I/usr/local/include
GLFW3FLAGS = `pkg-config --static --libs glfw3`

#Set directories for src, objs, and bin
SRCDIR	= src
OBJDIR	= obj
BINDIR	= bin

SOURCES		:= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES	:= $(wildcard $(SRCDIR)/*.hpp)
OBJECTS		:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm	= rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(GLFW3FLAGS) $(OBJECTS) $(THREADS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(CXXFLAGS) $(THREADS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

