#include <stdio.h>

#define MAX_SIZE 1000

int get_line(char a[]);
void entab(char c[], int size, int spaces);
void print(char c[], int size);

main() {

    char input[MAX_SIZE];
    int len;
    while((len = get_line(input)) != 0) {
        //Note; this also prints
        entab(input, len, 4);
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

void print(char c[], int size) {
    for(int i = 0; i < size; ++i) {
        putchar(c[i]);
    }
}
