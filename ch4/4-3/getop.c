#include <stdio.h>
#include <ctype.h>
#include "calc.h"

//Get next operator or numeric operand
int getop(char s[]) {
    int i, c;

    //Skip over whitespace or tab characters
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    //Close string right after found character
    s[1] = '\0';
    //If it's an operator, return it
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    i = 0;
    //If it's a digit, or a sign, overwrite s with all digits found afterwards
    if (isdigit(c) || c == '-') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    //If a . is next, write all digits found next
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    //Close string
    s[i] = '\0';
    //And, assuming we didn't get EOF, ungetch the last char found (as we read one too many)
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}
