# Compiler
CXX = g++

# Target executable
TARGET = passwddotexe.exe

# Source files
SRCS = main.cpp PasswordManager.cpp

# Default rule
all:
	$(CXX) $(SRCS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
