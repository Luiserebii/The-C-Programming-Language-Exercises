#include <stdio.h>
#include <time.h>

void printtime(char s[], clock_t start, clock_t end);
int binsearch(int x, int v[], int n);
int binsearchnew(int x, int v[], int n);

int main() {
    printf("Timing binary search implementations\n");
    clock_t s1, e1, s2, e2;

    int arr[] = {0, 10, 15, 20, 30, 45, 55, 75, 80, 85, 95, 100};
    int search = 15;
    int size = 12;

    //Time the first
    s1 = clock();
    binsearch(search, arr, size);
    e1 = clock();
    printtime("binsearch: ", s1, e1);

    //Time the new
    s2 = clock();
    binsearchnew(search, arr, size);
    e2 = clock();
    printtime("binsearchnew: ", s2, e2);

}

void printtime(char s[], clock_t start, clock_t end) {
    printf("%s %g ms\n", s, ((double) (end - start)) * 1000 / CLOCKS_PER_SEC);
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
