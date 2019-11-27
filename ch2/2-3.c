#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1;
#define FALSE 0;

int htoi(char[] s);
int isHexDigit(char c);
int prependedHex(char[] s);

int main() {
    
    printf("Testing htoi(char[] s): \n\n");
    printf("0x7DE: %d", htoi("0x7DE"));
}

int htoi(char[] s) {
    //Obtain starting point, depending on whether is prepended
    int start = prependedHex(s) ? 2 : 0;
    //Get length of hex
    int length = 0;
    for(int i = start; i < strlen(s) && isHexDigit(s[i]); ++i, ++len)
        ;

    //Finally, let's calculate the value
    int val = 0;
    for(int i = start; i < length; ++i) {
        val += hdtoi(s[i]) * pow(16, length - i - 1);
    }
    return val;
}

int isHexDigit(char c) {
    return ('0' <= c && c <= '9') || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f');
}

//Determines whether hex is prepended by "0x" or "0X" or not
int prependedHex(char[] s) {
    return s[0] == '0' && (s[1] == 'x' || s[1] == 'X');
}
