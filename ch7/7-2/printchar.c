#include <stdio.h>
#include <ctype.h>

#include "printchar.h"

int numprint = 0;

/** 
 * Returns number of chars printed, 0 if failure
 *
 * NOTE: Relies on var to maintain global state (numprint);
 * appropriate as a seperate module
 */
int printChar(int c, enum printCharMode mode) {
    //Determine number of digits to print based on mode
    int digits;
    switch(mode) {
        case NORMAL:
            digits = 1;
            break;
        case OCTAL:
            digits = numOctalDigits(c);
            break;
        default:
            //We shouldn't reach here; return 0
            return 0;
            break;
    }

    //Print newline depending on numchar printed so far
    if(numprint + digits > MAXLINE_CHARS) {
        putchar('\n');
        numprint = 0;
    }

    //Print the char
    switch(mode) {
        case NORMAL:
            putchar(c);
            break;
        case OCTAL:
            printf("%o", c);
            break;
    }

    //Finally, increment numprint by digits
    numprint += digits;

    return digits;
}

int numDigits(int n, int base) {
    int digits;
    for(digits = 0; n > 0; ++digits) {
        n /= base;
    }
    return digits;
}
