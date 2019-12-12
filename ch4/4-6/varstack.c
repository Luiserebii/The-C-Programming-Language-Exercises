#include <stdio.h>
#include "varstack.h"
#define MAXVAL 100

int sp = 0;
char val[MAXVAL];

// push: push f onto value stack
void pushVar(char f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// pop: pop and return top value from stack
char popVar(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
