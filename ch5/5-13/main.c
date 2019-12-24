#include <stdio.h>
#include <stdlib.h>

#include "buffer.h"

#define MAX_LEN 1000
#define LINES_DEFAULT 10

void tail(int lines);
int getLine(char s[], int lim);

int main(int argc, char* argv[]) {
    
    if(--argc > 1 && (*++argv)[0] == '-') {
        if((*argv)[1] != 'n') {
            printf("Invalid option, usage: tail -n num_lines\n");
            return 1;
        }
        //Grab number of memes
        int lines = atoi(*++argv);
        tail(lines);
        return 0;
    }

    //Call tail with the default number of lines
    tail(LINES_DEFAULT);

}

void tail(int lines) {
    //Silently set to max lines, if over
    if(lines > MAX_LINES) {
        lines = MAX_LINES;
    }
    char line[MAX_LEN];
    while(getLine(line, MAX_LEN)) {
        printf("LINE: %s | %d\n", line, lines);
        buffer_push(line);
    }
    //Print according to number of lines requested
    buffer_print(lines);
}

int getLine(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

