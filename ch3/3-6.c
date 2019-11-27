#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[], int pad);

int main() {

    int a = 100;
    char s[1000];
    printf("a: %d\n", a);
    itoa(a, s, 5);
    printf("Padding 5: %s\n", s);
    itoa(a, s, 15);
    printf("Padding 15: %s\n", s);
}


void itoa(int n, char s[], int pad) {

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
    while(i < pad) {
        s[i++] = ' ';
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

