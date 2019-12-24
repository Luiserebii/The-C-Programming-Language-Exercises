#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dcl.h"
#include "getch.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */ 
char out[1000]; /* output string */


int main() {
    int type;
    char temp[MAXTOKEN];

    while(gettoken() != EOF) {
        strcpy(out, token);
        while((type = gettoken()) != '\n') {
            if(type == PARENS || type == BRACKETS) {
                strcat(out, token);
            } else if(type == '*') {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if(type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

void dcl() {
    int ns;

    for(ns = 0; gettoken() == '*';) {
        ++ns;
    }
    dirdcl();
    while(ns-- > 0) {
        strcat(out, " pointer to");
    }
}

void dirdcl() {
    int type;

    if(tokentype == '(') {
        dcl();
        if(tokentype != ')') {
            printf("error: missing )\n");
        }
    } else if(tokentype == NAME) {
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\n");
    }
    while((type = gettoken()) == PARENS || type == BRACKETS) {
        if(type == PARENS) {
            strcat(out, " function returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
    
}

int gettoken(void) {
    int c;
    char* p = token;

    while((c = getch()) == ' ' || c == '\t')
        ;
    if(c == '(') {
        if((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if(c == '[') {
        for(*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if(isalpha(c)) {
        for(*p++ = c; isalnum(c = getch());) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}
