#include <stdio.h>

#define MAX_SIZE 1000

int get_line(char a[]);
void detab(char c[], int size, int spaces);
void print(char c[], int size);

main() {

    char input[MAX_SIZE];
    int len;
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
