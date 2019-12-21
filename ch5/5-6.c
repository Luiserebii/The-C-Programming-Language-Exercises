#include <stdio.h>
#include <ctype.h>

int getLine(char s[], int lim);
int atoi(char s[]);

int main() {

    printf("Conversion: %d\n", atoi("2502"));

    char line[1000];
    while(getLine(line, 1000)) {
        printf("%s", line);
    }
}

int atoi(char s[]) {
    int n, sign;

    //Skip whitespace
    while(isspace(*s) && ++s)
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
        ++s;
    }
    for (n = 0; isdigit(*s); ++s) {
        n = 10 * n + (*s - '0');
    }
    return sign * n;
}

int getLine(char s[], int lim) {
    int c;

    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return 1;
}
