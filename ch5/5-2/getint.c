#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "getch.h"

int getint(int *pn);
int getfloat(float *pn);

int main() {
    
    for(;;) {
        float OwO;
//        int res = getint(&OwO);
        float res = getfloat(&OwO);
        if(res) {
            printf("Float read: %f\n\n", OwO);
        } else {
            printf("Hit end\n");
        }
    }

}

int getfloat(float *pn) {
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
    //Process depending if next char is .
    if(c == '.') {
        for(int level = 1; c = getch(), isdigit(c); ++level) {
            *pn += ((float) (c - '0')) / pow(10, level);
        }
    }
    *pn *= sign;
    //Unless it's EOF, just ungetch the non-digit
    if(c != EOF) {
        ungetch(c);
    }

    return c;
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
