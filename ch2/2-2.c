#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

main() {

    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("I read a line OwO\n");
    }
    return 0;
}

int get_line(char s[], int lim) {

    int c, i;
    
    //Loop in getting a char until we hit the limit, EOF, or a newline
    for (i = 0; i < lim - 1; ++i) {
        if((c = getchar()) == EOF) {
            break;
        }
        if(c == '\n') {
            break;
        }
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

