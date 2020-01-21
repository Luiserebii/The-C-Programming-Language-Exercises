#include <stdio.h>
#include <ctype.h>

#define MAXLINE_CHARS 10

int numDigits(int n, int base);

/* Defining as macro for efficiency */
#define numOctalDigits(n) numDigits(n, 8)

int main() {

    int c;
    int numprint = 0;
    while((c = getchar()) != EOF) {
        //Apply logic on whether graphic or not using iscntrl
        //Non-graphic chars are control characters
        if(iscntrl(c)) {
            //Print octal
            int digits = numOctalDigits(c);
            if(numprint + digits > MAXLINE_CHARS) {
                putchar('\n');
                numprint = 0;
            }
            printf("%o", c);
            numprint += digits;
        } else {
            //Print char normally
            if(numprint + 1 > MAXLINE_CHARS) {
                putchar('\n');
                numprint = 0;
            }
            putchar(c);
            ++numprint;
        }
    }
}

int numDigits(int n, int base) {
    int digits;
    for(digits = 0; n > 0; ++digits) {
        n /= base;
    }
    return digits;
}
