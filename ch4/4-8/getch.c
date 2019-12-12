#include <stdio.h>
#define BUFSIZE 100

static char buf = 0;

int getch(void) { //Get a (possibly pushed back) character
    //Return char and set back to 0 if we have something in the buffer
    if(buf) {
        char ret = buf;
        buf = 0;
        return ret;
    } else {
        return getchar();
    }
}

void ungetch(int c) { // Push character back on input
    //Depending on whether or not the buffer is full, place the gotten char back on
    if (buf) {
        printf("ungetch: too many characters");
    } else {
        buf = c;
    }
}
