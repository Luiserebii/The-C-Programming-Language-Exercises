#include "sort.h"
#include <string.h>

// qsort: sort v[left]...v[right] into increasing order
void qsort(void* v[], int left, int right,
           int (*comp)(void*, void*)) {

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
        if((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    //Retore partition element
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

void swap(void* v[], int i, int j) {
    void* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

