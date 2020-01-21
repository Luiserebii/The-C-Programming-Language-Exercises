# ===========================================
# Default rule to simply make all and clean 
# ===========================================
#
# NOTE: This default rule actually defeats the purpose of a Makefile!
# The ideal refactor is one that compiles the object files into a seperate
# build folder, which will keep things clean and easy to .gitignore.
#
simple: all clean

# Rule to make all; noting object files as dependencies to compile based on age
all: main.o printchar.o
	cc main.o printchar.o
# Create rules for object files
main.o: main.c
	cc -c main.c
printchar.o: printchar.c printchar.h
	cc -c printchar.c
clean: 
	rm main.o printchar.o
