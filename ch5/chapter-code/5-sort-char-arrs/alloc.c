#include "alloc.h"

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* Storage for alloc */
static char *allocp = allocbuf; /* Next free position */

//Return pointer to n characters
char* alloc(int n) {

    //Check if it fits
    if(allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; //return pointer
    } else {
        //Since 0 is never a valid address type, we can
        //use this to signal that something is up
        return 0;
    }
}

//Free storage pponted to by p
void afree(char* p) {
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}
