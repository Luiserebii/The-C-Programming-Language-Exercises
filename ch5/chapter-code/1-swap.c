#include <stdio.h>

void printInts(int a, int b);
void swap(int* a, int* b);

int main() {
    
    int a, b;
    a = 10, b = 20;
    printInts(a, b);
    swap(&a, &b);
    printInts(a, b);
}

void swap(int* a, int* b) {
    int* temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void printInts(int a, int b) {
    printf("a: %d    b: %d", a, b);
}
