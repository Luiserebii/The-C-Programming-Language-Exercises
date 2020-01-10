#ifndef SORT_H
#define SORT_H

void q_sort(void* v[], int left, int right, int (*comp)(void*, void*), int fold, int dirorder);
void swap(void* v[], int i, int j);
int str_cmp(char* s, char* t);
int numcmp(char* s1, char* s2);
void tolowerstr(char* s);

#endif
