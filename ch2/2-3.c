#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1;
#define FALSE 0;

int htoi(char[] s);
int prependedHex(char[] s);

int main() {
    
    printf("Testing htoi(char[] s): \n\n");
    printf("0x7DE: %d", htoi("0x7DE"));
}

int htoi(char[] s) {
    int start = prependedHex(s) ? 2 : 0;

}

//Determines whether hex is prepended by "0x" or "0X" or not
int prependedHex(char[] s) {
    return s[0] == '0' && (s[1] == 'x' || s[1] == 'X');
}
