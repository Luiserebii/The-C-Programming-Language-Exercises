#include <stdio.h>

void strcatI(char* s, char* t);

int main() {
    char uguu[100] = "uwu";
    char* OwO = "Hello memes";
    printf("a: %s   b: %s\n", uguu, OwO);
    strcatI(uguu, OwO);
    printf("a: %s   b: %s\n", uguu, OwO);
}

void strcatI(char* s, char* t) {
    //Find end of s
    while(*++s)
        ;
    //Copy t in
    while(*s++ = *t++)
        ;
}
