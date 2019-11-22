#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main() {

    int len; //current line length
    int max; //maximum length seen so far
    char line[MAXLINE]; // current input line
    char longest[MAXLINE]; //longest line saved here

    max = 0;
    //Loop in loading a line (as char[]) into line (array passing is essentially by reference - what
    //is passed is the location/address of the beginning of the array)
    while ((len = get_line(line, MAXLINE)) > 0) {
        //If the line is the longest, let's save it into longest
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
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
