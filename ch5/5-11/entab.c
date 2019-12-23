#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int get_line(char a[]);
void entab(char c[], int size, int spaces);
void entab(char c[], int size, int tabstops[], int tsize);
void convert(int a[], char* s[], int size);

void print(char c[], int size);

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
                entab(input, len, list, argc);
            }
            return 0;
        }
    }

    while((len = get_line(input)) != 0) {
        //Note; this also prints
        entab(input, len, 5);
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

void entab(char c[], int size, int spaces) {
    int numSpaces = 0;
    for(int i = 0; i < size; ++i) {
        if(c[i] == ' ') {
            ++numSpaces;
            //If we have the right amount of spaces to entab,
            //do it!
            if(numSpaces == spaces) {
                putchar('\t');
                numSpaces = 0;
            }
        } else {
            //In the event we hit another char
            //and we haven't cleared our spaces:
            if(numSpaces != 0) {
                for(int sp = 0; sp < numSpaces; ++sp) {
                    putchar(' ');
                }
                numSpaces = 0;
            }
            putchar(c[i]);
        }
    }
}

void entab(char c[], int size, int tabstops[], int tsize) {
    for(int i = 0; i < tsize; ++i) {
        printf("STOP: %d\n", tabstops[i]);
    }
}

void print(char c[], int size) {
    for(int i = 0; i < size; ++i) {
        putchar(c[i]);
    }
}
