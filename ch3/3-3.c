#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[]);
int iswhitespace(char c);

int main() {

    char a[] = "-Hi, I really like a-z, especially a-z0-9 and a-b-c. Not to mention -a-z!";
    char b[1000];

    printf("a: %s\n", a);
    expand(a, b);
    printf("expand: %s\n", b);

}

void expand(char s1[], char s2[]) {
    int size = strlen(s1);
    //We keep track of writing to s2 with j
    for(int i = 0, j = 0; i < size; ++i, ++j) {
        switch (s1[i]) {
            case '-':
                if(i == 0 || i == size - 1 || iswhitespace(s1[i - 1])) {
                    //Write regularly
                    s2[j] = s1[i];
                } else {
                    //Grab the limit character
                    int lim = s1[i + 1];
                    //Loop through the char sequence, using the second as the limiter
                    //We can do this because of the way chars are aligned!
                    for(int ch = s1[i - 1] + 1; ch <= lim; ++ch) {
                        //Write the next char to come
                        s2[j++] = ch;
                    }
                    //Increment i to skip over the limit char
                    printf("\ni: %c, i + 2: %c\n", s1[i], s1[i+2]);
                    i += 2;
                }
            default:
                s2[j] = s1[i];
        }
    }

}

int iswhitespace(char c) {
    return (c == ' ') ? TRUE : FALSE;
}
