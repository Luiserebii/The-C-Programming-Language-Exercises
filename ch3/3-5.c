#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main() {

    int a = 100;
    char s[1000];
    printf("a: %d\n", a);
    itob(a, s, 10);
    printf("Base 10: %s\n", s);
    itob(a, s, 16);
    printf("Base 16: %s\n", s);
}


void itob(int n, char s[], int b) {

    int i, sign;
    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % b + '0';
    } while ((n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}


//Reverse string s in place
void reverse(char s[]) {
    int c, i, j;

    //Usage of comma operator to declare twice
    //Not to be confused with delimiter for function args,
    //and var declarations
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

