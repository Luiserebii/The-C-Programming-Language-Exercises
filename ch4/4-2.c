#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main() {
    printf("Testing atof:\n");
    char a[] = "123.45e-6";
    char b[] = "12e4";

    printf("%s: %f\n", a, atof(a));
    printf("%s: %f\n", b, atof(b));
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
    
    //Check if we have an exponent
    if (s[i] == 'e' || s[i] == 'E') {
        ++i;
    }
    //Grab sign, and advance as needed
    int expsign;
    if (s[i] == '-') {
        expsign = -1;
        ++i;
    } else {
        expsign = 1;
    }
    //Grab val
    double expval;
    for (expval = 0.0; isdigit(s[i]); ++i) {
        expval = 10.0 * expval + (s[i] - '0');
    }
    
    //Add to power depending on value obtained
    if (expsign == -1) {
        power *= pow(10, expval);
    } else {
        power /= pow(10, expval);
    }

    //Return evaluation based on info collected
    return sign * val / power;
}
