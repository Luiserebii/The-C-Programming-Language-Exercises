#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int isalphalower(char c);

//Get next operator or numeric operand
int getop(char s[]) {
    int i;
    //Keep static var, allowing us to not ungetch()
    static int c = 0;
    //Skip over whitespace or tab characters
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    //Close string right after found character
    s[1] = '\0';
    //If it's a var, return it and return enum
    if (isalphalower(c)) {
        return VARIABLE;
    }
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

    return NUMBER;
}

int isalphalower(char c) {
    return 'a' <= c && c <= 'z';
}
