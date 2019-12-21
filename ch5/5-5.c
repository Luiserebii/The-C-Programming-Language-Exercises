#include <stdio.h>

char* strncpy(char* s, char* ct, int n);
char* strncat(char* s, char* ct, int n);
int strncmp(char* cs, char* ct, int n);

void teststrncpy();
void teststrncat();
void teststrncmp();


int main() {
    teststrncpy();    
    teststrncat();
    teststrncmp();
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

int strncmp(char* cs, char* ct, int n) {
    //While the chars are equal and neither one is '\0'
    for(int i = 0; i != n - 1 && *cs == *ct && *cs && *ct; ++i) {
        //We increment here, as we don't want to increment if
        //we did hit '\0'
        cs++, ct++;
        //Though, we can change order of && I bet and achieve same solution, test this
    }
    //We're at a char that can be compared, or both are equal
    //Return the difference, i.e. comparison of the nth char
    return *cs - *ct;
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
    printf("========\nTesting strncat\n========\n");
    char a[1000] = "Hello!";
    char* b = "OwO, what's this?";

    printf("a: %s   b: %s\n", a, b);
    strncat(a, b, 100);
    printf("a: %s   b: %s\n", a, b);
    strncat(a, b, 2);
    printf("a: %s   b: %s\n", a, b);
}

void teststrncmp() {
    printf("========\nTesting strncmp\n========\n");
    char* a = "animal";
    char* b = "animate";

    printf("a: %s   b: %s\n", a, b);
    printf("strncmp(a, b, 10): %d\n", strncmp(a, b, 10));
    printf("strncmp(a, b, 4): %d\n", strncmp(a, b, 4));
    printf("strncmp(a, b, 5): %d\n", strncmp(a, b, 5));
}
