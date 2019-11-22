#include <stdio.h>

#define MAXLINE 1000

/**
 * Defining variables externally
 */

int max; //maximum length seen so far
char line[MAXLINE]; // current input line
char longest[MAXLINE]; //longest line saved here
        
int get_line();
void copy();

main() {

    int len; //current line length
    extern int max;
    extern char longest[MAXLINE];

    max = 0;
    //Loop in loading a line (as char[]) into line (array passing is essentially by reference - what
    //is passed is the location/address of the beginning of the array)
    while ((len = get_line()) > 0) {
        //If the line is the longest, let's save it into longest
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}

//Read a line into the char[] passed, return length
int get_line(void) {

    int c, i;
    extern char line[];
    
    //Loop in getting a char until we hit the limit, EOF, or a newline
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        //Append to char[]
        line[i] = c;
    }

    //If we hit a newline, add it
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    //Add final piece to char array - a null character
    line[i] = '\0';
    return i;
}

//Copy a char[] 'from' into 'to'; assumes is large enough
void copy(void) {

    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}
