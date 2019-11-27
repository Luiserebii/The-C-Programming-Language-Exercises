#include <stdio.h>

#define TRUE 1
#define FALSE 0

int any(char s1[], char s2[]);
int matches(char c, char s[]);

int main() {

    char a[] = "Hello world!";
    char b[] = "aaaa";

    printf("a: %s\nb: %s\n", a, b);
    printf("any(): %d\n", any(a, b));
}

int any(char s1[], char s2[]) {
    for(int i = 0; s1[i] != '\0'; ++i) {
        if(matches(s1[i], s2)) {
            return i;
        }
    }
    return -1;
}

//Returns if char c matches within the second char[] passed
int matches(char c, char s[]) {
    for(int i = 0; s[i] != '\0'; ++i) {
        if(s[i] == c) return TRUE;
    }
    return FALSE;
}
