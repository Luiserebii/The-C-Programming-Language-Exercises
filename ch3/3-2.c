#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]);

int main() {

    char a[] = "Uguu\nOwO\t\t\n";
    char b[1000];
    printf("a: %s", a);
    escape(b, a);
    printf("escape: %s", a);
}


void escape(char s[], char t[]) {
    int len = strlen(t);
    //j is used to track our writing through s,
    //needed as we sometimes will be mapping a char
    //to multiple chars
    for(int i = 0, int j = 0; i < len; ++i, ++j) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
        } 
    }
}
