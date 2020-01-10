#include "sort.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

// qsort: sort v[left]...v[right] into increasing order
void q_sort(void* v[], int left, int right,
           int (*comp)(void*, void*), int fold) {

    int i, last;
    //If arr contains less than two elements, return
    if (left >= right) {
        return;
    }
    //Move partition element to v[0]
    swap(v, left, (left + right)/2);
    last = left;
    //Partition
    for (i = left + 1; i <= right; ++i) {
        //If we're folding, compare the lowercase version
        if(fold) {
            char* lowerI = tolowerstr(v[i]);
            char* lowerLeft = tolowerstr(v[left]);

            if((*comp)((void*) tolowerstr(v[i]), (void*) tolowerstr(v[left])) < 0) {
                swap(v, ++last, i);
            }
        } else {
            if((*comp)(v[i], v[left]) < 0) {
                swap(v, ++last, i);
            }
        }
    }
    //Restore partition element
    swap(v, left, last);
    q_sort(v, left, last - 1, comp, fold);
    q_sort(v, last + 1, right, comp, fold);
}

void swap(void* v[], int i, int j) {
    void* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int str_cmp(char* s, char* t) {
    for(; *s == *t; ++s, ++t) {
        if(*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

int numcmp(char* s1, char* s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2) {
        return -1;
    } else if(v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}


