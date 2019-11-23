#include <stdio.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

int get_line(char a[]);

main() {

    char input[MAX_SIZE];
    int len;

    //Hold whether we are in string literal or not
    while((len = get_line(input)) != 0) {
        int inProtected = FALSE;
        int canPrint = FALSE;
        for(int i = 0; i < len; ++i) {
            if(input[i] == '"') {
                //Swap between protected or not depending on whether we hit
                //this a second time
                inProtected == FALSE ? inProtected = TRUE : inProtected = FALSE ;
            } else if(input[i] == "//" && inProtected == FALSE) {
                //We hit a comment; stop printing
                break;
            } else if(input[i] == "/*" && inProtected == FALSE) {
                canPrint = FALSE;
            } else if(input[i] == "*/" && inProtected == FALSE) {
                canPrint = TRUE;
            } else {
                if(canPrint == TRUE) {
                    putchar(input[i]);
                }
            }
        }

    }

}

int get_line(char a[]) {
    int c;
    int i;
    for(i = 0; i < MAX_SIZE - 1 && ((c = getchar()) != '\n') && c != EOF; ++i) {
        a[i] = c;
    }
    if(c == '\n') {
        a[i] = c;
        ++i;
    }

    a[i] = '\0';
    return i;
}

