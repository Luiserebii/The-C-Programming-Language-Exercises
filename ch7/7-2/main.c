#include <stdio.h>
#include <ctype.h>

#define MAXLINE_CHARS 10

int numOctalDigits(int n);

int main() {

    int c;
    int numprint = 0;
    while((c = getchar()) != EOF) {
        //Apply logic on whether graphic or not using iscntrl
        //Non-graphic chars are control characters
/*        if(iscntrl(c)) {
            //Print octal
            printf("%o", c);
        } else {
            //Print char normally
            putchar(c);
            ++numprint;
            if()
        }  */
        printf("%o | DIGITS PRINTED: %d\n", c, numOctalDigits(c));
    }

}

int numOctalDigits(int n) {
    int digits;
    for(digits = 0; n > 0; ++digits) {
        n /= 8;
    }
    return digits;
}
