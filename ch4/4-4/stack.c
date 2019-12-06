#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

// push: push f onto value stack
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// pop: pop and return top value from stack
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
// Return top of stack, no push
double stacktop(void) {
    if (sp > 0) {
        return val[sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Duplicate top of stack, returns value duplicated
double stackduptop(void) {
    if (sp > 0) {
        val[sp + 1] = val[sp];
        return val[sp++];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Clear stack
void stackclear(void) {
    //Arguably, we don't even have to hard-clear these
    //values, since sp tells us whether we have stuff or not
    for (int i = 0; i < sp; ++i) {
        val[i] = 0;
    }
    sp = 0;
}
