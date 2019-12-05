#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;

int getch(void) { //Get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { // Push character back on input
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters");
    } else {
        buf[bufp++] = c;
    }
}
