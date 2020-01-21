# Default rule to simply make all and clean 
default: all clean

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
