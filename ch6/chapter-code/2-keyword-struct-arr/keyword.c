#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "keyword.h"
#include "getch.h"

struct key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

// binsearch:   find word in tab[0]...tab[n-1]
int binsearch(char* word, struct key tab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid].word)) < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    //We didn't find anything, so return -1
    return -1;
}

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
