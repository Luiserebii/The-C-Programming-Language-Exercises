#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1;
#define FALSE 0;

int htoi(char[] s);
int hdtoi(char c);
int isHexDigit(char c);
int prependedHex(char[] s);

int main() {
    
    printf("Testing htoi(char[] s): \n\n");
    printf("0x7DE: %d", htoi("0x7DE"));
}

/**
 * Converts hex char[] to int. Note that it is assumed the value
 * is trimmed at the beginning, whitespace is not ignored; the only
 * thing done is ignoring non-hex chars at the end
 */
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

//Converts single hex digit to integer
int hdtoi(char c) {
    if('0' <= c && c <= '9') {
        return c - '0';
    } else if('A' <= c && c <= 'F') {
        return c - 'A' + 10;
    } else if('a' <= c && c <= 'f') {
        return c - 'a' + 10;
    }
}

int isHexDigit(char c) {
    return ('0' <= c && c <= '9') || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f');
}

//Determines whether hex is prepended by "0x" or "0X" or not
int prependedHex(char[] s) {
    return s[0] == '0' && (s[1] == 'x' || s[1] == 'X');
}
