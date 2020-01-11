#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "keyword.h"
#include "getch.h"

// binsearch:   find word in tab[0]...tab[n-1]
struct key* binsearch(char* word, struct key* tab, int n) {
    int cond;
    struct key* low = &tab[0];
    struct key* high = &tab[n];
    struct key* mid;

    while(low < high) {
        mid = low + (high - low) / 2;
        if((cond = strcmp(word, mid->word)) < 0) {
            high = mid;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    //We didn't find anything, so return NULL
    return NULL;
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
