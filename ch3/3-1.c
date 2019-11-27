#include <stdio.h>
#include <time.h>

void printtime(char s[], clock_t start, clock_t end);
int binsearch(int x, int v[], int n);
int binsearchnew(int x, int v[], int n);

int main() {
    printf("Timing binary search implementations\n");
    clock_t s1, e1, s2, e2;

    //Time the first
    s1 = clock();
    binsearch();
    e1 = clock();
    printtime("binsearch: ", s1, e1);

    //Time the new
    s2 = clock();
    binsearchnew();
    e2 = clock();
    printtime("binsearchnew: ", s2, e2);

}

void printtime(char s[], clock_t start, clock_t end) {
    printf("%s %f sec", s, ((double) (end - start)) / CLOCKS_PER_SEC);
}

int binsearchnew(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid; //Match found!
        }
    }
    return -1; //No match found
}

//Binary search: find x in v[0] <= v[1] <= ...
//<= v[n - 1]
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid; //Match found!
        }
    }
    return -1; //No match found
}
