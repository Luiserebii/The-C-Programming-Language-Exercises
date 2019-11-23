#include <stdio.h>

//Deciding to use this macros, as partial practice
#define TRUE 1
#define FALSE 0

main() {

    int c;
    int isWhitePrinted = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            //If we haven't encountered and printed a whitespace yet, print and 
            //set state
            if (isWhitePrinted == FALSE) {
                putchar(' ');
                isWhitePrinted = TRUE;
            }
        } else {
            //If we encounter any other char, make state FALSE
            isWhitePrinted = FALSE;
            putchar(c);
        }
    
    }
}
