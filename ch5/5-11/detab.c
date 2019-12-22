#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int get_line(char a[]);
void detab(char c[], int size, int spaces);
void print(char c[], int size);
void convert(int a[], char* s[], int size);

main(int argc, char* argv[]) {

    char input[MAX_SIZE];
    int len;

    //If we have at least two args and the nearest one is a flag
    if(argc-- > 1 && (++argv)[0] == '-') {
        if(argv[1] == 'l') {
            //Process logic to generate list
            int list[MAX_SIZE];
            convert(list, ++argv, --argc);
        }
    }

    while((len = get_line(input)) != 0) {
        //Note; this also prints
        detab(input, len, 4);
    }

}

int get_line(char a[]) {
    int c;
    int i;
    for(i = 0; i < MAX_SIZE - 1 && ((c = getchar()) != '\n') && c != EOF; ++i) {
        a[i] = c;
    }
    if(c == '\n') {
        a[i] = c;
        ++i;
    }

    a[i] = '\0';
    return i;
}

void convert(int a[], char* s[], int size) {
    //Maybe doesn't matter, but this saves on a var
    //(Contrast, vs. for loop)
    while(size--) {
        a[size] = atoi(s[size]);
    }
}

//n should be a symbolic parameter!
void detab(char c[], int size, int spaces) {
    for(int i = 0; i < size; ++i) {
        if(c[i] == '\t') {
            for(int j = 0; j < spaces; ++j) {
                putchar(' ');
            }
        } else { 
            putchar(c[i]);
        }
    }
}

void print(char c[], int size) {
    for(int i = 0; i < size; ++i) {
        putchar(c[i]);
    }
}
