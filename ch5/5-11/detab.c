#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int get_line(char a[]);
void detab(char c[], int size, int spaces);
void detab(char c[], int size, int tabstops[], int tsize);
void convert(int a[], char* s[], int size);

// Utility functions
void print(char c[], int size);
void print(int c[], int size);

main(int argc, char* argv[]) {

    char input[MAX_SIZE];
    int len;

    //If we have at least two args and the nearest one is a flag
    if(argc-- > 1 && (*++argv)[0] == '-') {
        if((*argv)[1] == 'l') {
            //Process logic to generate list
            int list[MAX_SIZE];
            convert(list, ++argv, --argc);
            //Enter appropriate loop
            while((len = get_line(input)) != 0) {
                detab(input, len, list, argc);
            }
            return 0;
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

void detab(char c[], int size, int tabstops[], int tsize) {
    int written = 0;
    for(int i = 0; i < size; ++i) {
        if(c[i] == '\t') {
            int tabs = 0;
            //Obtain relevant tabstop
            for(int j = 0; j < tsize; ++j) {
                if(written < tabstops[j]) {
                    tabs = tabstops[j];
                    break;
                }
            }
            //If we didn't find one, then use the most exaggerated one
            if(!tabs) {
                tabs = tabstops[tsize - 1];
            }
            //Finally, print!
            //tabs - written will represent the number of spaces we need to hit up to
            //printf("Using: tabs: %d, i: %d, diff: %d", tabs, written, tabs-written);
            int toWrite = tabs - written;
            for(int j = 0; j < toWrite; ++j) {
                putchar(' ');
                ++written;
            }
        } else {
            putchar(c[i]);
            ++written;
        }
    }
}

void print(char c[], int size) {
    for(int i = 0; i < size; ++i) {
        putchar(c[i]);
    }
}
void print(int c[], int size) {
    for(int i = 0; i < size; ++i) {
         printf("%d",c[i]);
    }
}
