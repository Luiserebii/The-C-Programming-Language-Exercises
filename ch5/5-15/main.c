#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lines.h"
#include "sort.h"

#define MAXLINES 5000

char* lineptr[MAXLINES];

//void sort(void* lineptr[], int left, int right, int (*comp)(void*, void*));
//int numcmp(char*, char*);
void toLowerStr(char* s);

/* Sort input lines */
int main(int argc, char* argv[]) {
    int nlines;
    int numeric = 0;
    int reverse = 0;
    int fold = 0;

    //Process all memes
    while(--argc){
        if(str_cmp(argv[argc], "-n") == 0) {
            numeric = 1;  
        } else if(str_cmp(argv[argc], "-r") == 0) {
            reverse = 1;
        } else if(str_cmp(argv[argc], "-f") == 0) {
            fold = 1;
        }
    }

    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        //This is arguably the least intrusive solution; pre-fold
        //the strings before comparing, instead of re-implementing each
        //cmp function to account for treating uppercase/lowercase similarly
        if(fold) {
            for(int i = 0; i < nlines; ++i) {
                toLowerStr(lineptr[i]);
            }
        }

        q_sort((void**) lineptr, 0, nlines - 1, 
                (int (*)(void*, void*))(numeric ? numcmp : str_cmp));
        //This is a lazy solution; reverse after the sort has happened
        if(reverse) {
            for(int i = 0; i < nlines/2; ++i) {
                swap((void**) lineptr, i, nlines - 1 - i);
            }
        }
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void toLowerStr(char* s) {
    while(*s) {
        *s = tolower(*s);
        ++s;
    }
}
