#include <stdio.h>
#include <ctype.h>
#include "getch.h"

int getint(int *pn);

int main() {
    
    for(;;) {
        int OwO;
        int res = getint(&OwO);
        if(res) {
            printf("Integer read: %d\n\n", OwO);
        } else {
            printf("Hit end\n");
        }
    }

}

/* getint:  get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;

    //Skip whitespace
    while(isspace(c = getch()))
        ;
    //In the case that it isn't a number, ungetch and return
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    //Set sign if exists
    sign = (c == '-') ? -1 : 1;
    //Skip over sign
    if(c == '+' || c == '-') {
        c = getch();
        if(!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }
    //Generate number char by char until not digit
    for(*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    //Unless it's EOF, just ungetch the non-digit
    if(c != EOF) {
        ungetch(c);
    }

    return c;
}
