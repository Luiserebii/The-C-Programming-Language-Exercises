#include <stdio.h>

#define TRUE 1
#define FALSE 0

main() {
    
    int c;
    int isNewlinePrinted = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' '){
            if (isNewlinePrinted == FALSE) {
                putchar('\n');
                isNewlinePrinted == TRUE;
            }
        } else {
            putchar(c);
            isNewlinePrinted = FALSE;
        }
    }

}
