#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void print(char c[], int size);
void reverse(char c[], int size);

main() {

    int len; //current line length
    char line[MAXLINE]; // current input line

    //Loop in loading a line (as char[]) into line (array passing is essentially by reference - what
    //is passed is the location/address of the beginning of the array)
    while ((len = get_line(line, MAXLINE)) > 0) {
        //Reverse
        reverse(line, len);
        print(line, len);
    }
    return 0;
}

//Read a line into the char[] passed, return length
int get_line(char s[], int lim) {

    int c, i;
    
    //Loop in getting a char until we hit the limit, EOF, or a newline
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        //Append to char[]
        s[i] = c;
    }

    //If we hit a newline, add it
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    //Add final piece to char array - a null character
    s[i] = '\0';
    return i;
}

//Copy a char[] 'from' into 'to'; assumes is large enough
void copy(char to[], char from[]) {

    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

//Print a char array
void print(char c[], int size) {
    for(int i = 0; i < size; ++i) {
        putchar(c[i]);
    }
}

void reverse(char c[], int size) {
    int temp;
    //Decrement to account for '\0' null char
    --size;
    for(int i = 0; i < size/2; ++i) {
        temp = c[i];
        c[i] = c[size - i - 1];
        c[size - i - 1] = temp;
    }
}
