#include <stdio.h>

main() {

    int c;
    int blanks, tabs, newlines;
    blanks = tabs = newlines = 0;
    while((c = getchar()) != EOF) {
        if(c == ' ') {
            blanks++;
        } else if(c == '\t') {
            tabs++;
        } else if(c == '\n') {
            newlines++;
        }
    }

    //Print this stuff out
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
}
