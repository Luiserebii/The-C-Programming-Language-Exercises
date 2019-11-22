#include <stdio.h>

main() {

    int c, nl;

    nl = 0;
    //Grab each line, if not EOF, and is \n, increment
    //'' makes '\n' a character, therefore an int in expressions
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
    }
    printf("%d\n", nl);

}
