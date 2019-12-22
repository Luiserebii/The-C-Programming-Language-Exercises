#include "lines.h"
#include "alloc.h"

#include <stdio.h>
#include <string.h>

int readlines(char* lineptr[], int maxlines) {
    int len, nlines;
    char* p, line[MAXLEN];

    nlines = 0;
    //Reading each line into line
    while((len = getLine(line, MAXLEN)) > 0) {
        //If the number is lines are too high, or
        //we are unable to allocate more, quit
        if(nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            //Delete newline
            line[len - 1] = '\0';
            //Copy to p
            strcpy(p, line);
            //Set and advance lineptr[] to new line
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char* lineptr[], int nlines) {
    for(int i = 0; i < nlines; ++i) {
        printf("%s\n", lineptr[i]);
    }
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

