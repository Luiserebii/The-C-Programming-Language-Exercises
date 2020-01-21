#include <stdio.h>
#define isuppermac(c) (c >= 'A' && c <= 'Z')

int isupper(int c);

int main() {
    char a = 'a';
    char b = 'A';
    printf("Testing isupper: %c is %d, %c is %d\n", a, isupper(a), b, isupper(b));
    printf("Testing isuppermac: %c is %d, %c is %d\n", a, isuppermac(a), b, isuppermac(b));
}

/**
 * This problem is kind of interesting; when it talked about saving
 * space/time, I assumed it was maybe having something to do with
 * algorithmic efficiency I wasn't seeing... but I am not so certain
 * it is that. 
 *
 * Looking at the C Answer Book, it seems to suggest that saving time
 * (by being faster) would be implemented isupper() as a macro as
 * opposed to a function, but would take more space by expanding...
 * I... guess that makes sense
 */
int isupper(int c) {
    return c >= 'A' && c <= 'Z';
}
