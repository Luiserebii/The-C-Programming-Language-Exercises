#include <stdio.h>

int strlen(char* s);
char* strncpy(char* s, char* ct, int n);
char* strncat(char* s, char* ct, int n);

void teststrncpy();
void teststrncat();


int main() {
    teststrncpy();    
    teststrncat();

}



char* strncpy(char* s, char* ct, int n) {
    for(int i = 0; i != n; ++i) {
        //This line is implicitly (*ct != '\0')
        if(*ct) {
            *s++ = *ct++;
        } else {
            *s++ = '\0';
        }
    }
    return s;
}

char* strncat(char* s, char* ct, int n) {
    //Head to the end, stop at null char
    while(*++s)
        ;
    //Iterate through while we haven't hit n chars,
    //and also stop once a null character has been copied
    for(int i = 0; (i != n) && (*s++ = *ct++); ++i)
        ;
    return s;
}





int strlen(char* s) {
    int i = 0;
    while(*s++) {
        ++i;
    }
    return i;
}

void teststrncpy() {
    printf("========\nTesting strncpy\n========\n");
    char a[1000] = "";
    char* b = "OwO, what's this?";
    char* c = "c";

    printf("a: %s   b: %s\n", a, b);
    strncpy(a, b, 10);
    printf("a: %s   b: %s\n", a, b);
    strncpy(a, c, 10);
    printf("a: %s   c: %s\n", a, c);
}

void teststrncat() {
    printf("========\nTesting strncpy\n========\n");
    char a[1000] = "Hello!";
    char* b = "OwO, what's this?";

    printf("a: %s   b: %s\n", a, b);
    strncat(a, b, 100);
    printf("a: %s   b: %s\n", a, b);
    strncat(a, b, 2);
    printf("a: %s   b: %s\n", a, b);
}
