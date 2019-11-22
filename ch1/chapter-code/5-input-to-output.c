#include <stdio.h>

main() {

    //int to hold higher values
    int c;

    //Assignment is an expression, so we can do this
    while((c = getchar()) != EOF) {
        putchar(c);
    }

}

/******************************
 * 1st version

#include <stdio.h>

main() {

    int c;
    c = getchar();

    while (c != EOF) {
        //Print a char
        putchar(c);
        c = getchar();
    }
}
*/
