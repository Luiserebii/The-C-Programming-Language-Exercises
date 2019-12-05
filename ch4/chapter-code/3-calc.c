#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int main() {
    double sum, atof(char []);
    char line[MAXLINE];
    int getLine(char line[], int max);

    sum = 0;
    while (getLine(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
}

//atof: convert string s to double
double atof(char s[]) {
    double val, power;
    int i, sign;

    //Skip whitespace
    for (i = 0; isspace(s[i]); ++i)
        ;
    //Grab sign, if it exists
    sign = (s[i] == '-') ? -1 : 1;
    //Advance past sign, if it exists
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }
    //Grab all digits and eval to val
    for (val = 0.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
    }
    //Advance past ., if it exists
    if (s[i] == '.') {
        ++i;
    }
    //Grab all digits post-., and keep track of power
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    //Return evaluation based on info collected
    return sign * val / power;
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
