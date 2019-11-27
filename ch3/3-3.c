#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main() {

    char a[] = "-Hi, I really like a-z, especially a-z0-9 and a-b-c. Not to mentione -a-z!";
    char b[1000];

    printf("a: %s", a);
    expand(a, b);
    printf("expand: %s", b);

}

void expand(char s1[], char s2[]) {
    int size = strlen(s1);
    //We keep track of writing to s2 with j
    for(int i = 0, j = 0; i < size; ++i, ++j) {
        switch (s1[i]) {
            case '-':
                if(i == 0 || i == size - 1) {
                    //Write regularly
                    s2[j] = s1[i];
                } else {
                    //Grab the limit character
                    int lim = s1[i + 1];
                    //Loop through the char sequence, using the second as the limiter
                    //We can do this because of the way chars are aligned!
                    for(int ch = s1[i - 1]; ch <= lim; ++ch) {
                        
                    }
                }
            default:
                s2[j] = s1[i];
        }
    }

}
