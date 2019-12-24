#ifndef SORT_H
#define SORT_H

void qsort(void* v[], int left, int right, int (*comp)(void*, void*));
void swap(void* v[], int i, int j);

#endif
