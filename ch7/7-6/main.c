#include <stdio.h>

int main(int argc, char** argv) {
    
    //Argument logic
    if(--argc != 2) {
        fprintf(stderr, "Invalid number of arguments passed, expected 2, received %d.\n", argc);
    }

    char* fn1 = argv[1];
    char* fn2 = argv[2];

    printf("Filename1: %s, Filename2: %s\n", fn1, fn2);

}
