#include <stdio.h>

//These are much like enums representing state
#define IN  1
#define OUT 0

main() {

    int c, nl, nw, nc, state;

    state = OUT;
    //Assignment as expression allows this
    nl = nw = nc = 0;

    while((c = getchar()) != EOF) {
        //Increment num of chars
        ++nc;
        //If it is a newline, increment num of newlines
        if (c == '\n') {
            ++nl;
        }

        //If we hit outside a word, set state to OUT
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            //Increment, if we came from out and are coming in
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
