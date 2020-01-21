#include <stdio.h>
#include <ctype.h>

#include "printchar.h"

int main() {

    int c;
    numprint = 0;
    while((c = getchar()) != EOF) {
        //Apply logic on whether graphic or not using iscntrl
        //Non-graphic chars are control characters
        if(iscntrl(c)) {
            printChar(c, OCTAL);
        } else {
            printChar(c, NORMAL);
        }
    }
}
