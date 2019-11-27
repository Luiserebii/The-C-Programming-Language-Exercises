#include <string.h>

//Reverse string s in place
void reverse(char s[]) {
    int c, i, j;

    //Usage of comma operator to declare twice
    //Not to be confused with delimiter for function args,
    //and var declarations
    for(i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
