#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;

int getch(void) { //Get a (possibly pushed back) character
    //If there are chars on the buffer, grab the latest on the buffer and decrement the size
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { // Push character back on input
    //Depending on whether or not the buffer is full, place the gotten char back on
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters");
    } else {
        buf[bufp++] = c;
    }
}

/**
 * To answer the question; ungets is better using ungetch(), as part of our logic is
 * solved for us there
 */
void ungets(char s[]) {
    while(*s != '\0') {
        ungetch(*s++);
    }
}
