#ifndef PRINTCHAR_H
#define PRINTCHAR_H

#include <stdio.h>
#include <ctype.h>

/**
 * Utility functions
 */
int numDigits(int n, int base);
/* Defining as macro for efficiency */
#define numOctalDigits(n) numDigits(n, 8)

/**
 * Main declarations
 */
#define MAXLINE_CHARS 10

extern int numprint;

enum printCharMode { NORMAL, OCTAL };
int printChar(int c, enum printCharMode mode);

#endif
