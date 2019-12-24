#include <stdio.h>
#include <string.h>
#include "lines.h"
#include "sort.h"

#define MAXLINES 5000

char* lineptr[MAXLINES];

//void sort(void* lineptr[], int left, int right, int (*comp)(void*, void*));
//int numcmp(char*, char*);

/* Sort input lines */
int main(int argc, char* argv[]) {
    int nlines;
    int numeric = 0;

    if(argc > 1 && str_cmp(argv[1], "-n") == 0) {
        numeric = 1;  
    }

    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        q_sort((void**) lineptr, 0, nlines - 1, 
                (int (*)(void*, void*))(numeric ? numcmp : str_cmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

