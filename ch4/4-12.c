#include <stdio.h>
#include <string.h>
#define MAX_STRING 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main() {
    
    printf("Testing itoa: \n");
    int a = 10;
    int b = 200;
    int c = -500;
    char s[MAX_STRING];

    itoa(a, s);
    printf("%d: %s\n", a, s);
    itoa(b, s);
    printf("%d: %s\n", b, s);
    itoa(c, s);
    printf("%d: %s\n", c, s);
}

void itoa(int n, char s[]) {

    int i = 0;
    //Process sign
    if (n < 0) {
        n = -n;
        s[i++] = '-';
    }
    if((n /= 10) = 0) {
        return;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    s[i] = '\0';
    reverse(s);
}

/*
void itoa(int n, char s[]) {

    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
*/
//Reverse string s in place
void reverse(char s[]) {
    int c, i, j;

    //Usage of comma operator to declare twice
    //Not to be confused with delimiter for function args,
    //and var declarations
    for(i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

