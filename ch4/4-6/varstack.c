#include <stdio.h>
#include "varstack.h"
#define MAXVAL 100

static int sp = 0;
static char val[MAXVAL];

// pushVar: push c onto variable stack
void pushVar(char c) {
    if (sp < MAXVAL) {
        val[sp++] = c;
    } else {
        printf("error: stack full, can't push %c\n", c);
    }
}

// popVar: pop and return top value from stack
char popVar(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
