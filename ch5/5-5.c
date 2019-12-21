#include <stdio.h>

int strlen(char* s);
char* strncpy(char* s, char* ct, int n);


int main() {
    
    char a[1000];
    char b* = "OwO, what's this?";
    char c* = "c";

    printf("a: %s   b: %s", a, b);
    strncpy(a, b, 10);
    printf("a: %s   b: %s", a, b);
    strncpy(a, c, 10);
    printf("a: %s   b: %s", a, b);


}



char* strncpy(char* s, char* ct, int n) {
    for(int i = 0; i != n; ++i) {
        if(*ct != '\0') {
            *s++ = *ct++;
        } else {
            *s++ = '\0';
        }
    }
}






int strlen(char* s) {
    int i = 0;
    while(*s++) {
        ++i;
    }
    return i;
}
