#include <stdio.h>

#define TRUE 1
#define FALSE 0

void squeeze_alt(char s1[], char s2[]);
int matches(char c, char s[]);

int main() {

    char a[] = "Hello world!";
    char b[] = "ole~";

    printf("a: %s\nb: %s\n", a, b);
    squeeze_alt(a, b);
    printf("squeeze_alt(): %s\n", a);

}

//Deletes each char in s1 that matches any char in s2
void squeeze_alt(char s1[], char s2[]) {
    int writepos = 0;
    for(int i = 0; s1[i] != '\0'; ++i) {
        //If it doesn't match...
        if(!matches(s1[i], s2)) {
            //Write the non-matching char (what we want)
            s1[writepos++] = s1[i];
        }
    }
    //Cap it all off with a null char
    s1[writepos] = '\0';
}

//Returns if char c matches within the second char[] passed
int matches(char c, char s[]) {
    for(int i = 0; s[i] != '\0'; ++i) {
        if(s[i] == c) return TRUE;
    }
    return FALSE;
}
