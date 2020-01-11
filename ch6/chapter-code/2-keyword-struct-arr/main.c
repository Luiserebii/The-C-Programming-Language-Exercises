#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getword(char* word, int lim);
int binsearch(char* word, struct key tab[], int n);

/* Count C keywords */
int main() {
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF) {
        if(isalpha(word[0])) {
            if((n = binsearch(word, keytab, NKEYS)) >= 0) {
                ++keytab[n].count;
            }
        }
    }

    for(n = 0; n < NKEYS; ++n) {
        if(keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;

}

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

    if(c != EOF) {
        *w++ = c;
    }

    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for(; --lim > 0; ++w) {
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
