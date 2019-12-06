#include <stdio.h>

int strrindex(char s[], char t);

int main() {
    
    char a[] = "Hello";
    char b[] = "OwO";

    printf("a: %s\nb: %s\n", a, b);
    printf("strrindex(a, 'e'): %d\n", strrindex(a, 'e'));
    printf("strrindex(a, 'o'): %d\n", strrindex(a, 'o'));
    printf("strrindex(b, 'x'): %d\n", strrindex(b, 'x'));

}

int strrindex(char s[], char t) {
    for(int i = 0; i != '\0'; ++i) {
        if(s[i] == t) {
            return i;
        }
    }
    //If we reached here, nothing was found
    return -1;
}

