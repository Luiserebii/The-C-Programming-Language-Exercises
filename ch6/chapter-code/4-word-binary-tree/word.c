#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "word.h"
#include "getch.h"

// getword:   get next word or character from input
int getword(char* word, int lim) {
    int c;
    char* w = word;
    
    while(isspace(c = getch()))
        ;

    //If not EOF, paste in and advance
    if(c != EOF) {
        *w++ = c;
    }

    //If non-alpha char, close string and return char val
    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }

    //Until the limit, read into our char*; in the case
    //of a non-alpha, ungetch and break, leaving *w as
    //the piece to close
    for(; --lim > 0; ++w) {
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    //Return first char val
    return word[0];
}
