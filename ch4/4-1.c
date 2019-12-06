#include <stdio.h>

int strrindex(char s[], char t);

int main() {
    
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

