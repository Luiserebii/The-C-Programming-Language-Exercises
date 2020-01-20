#include <stdio.h>

int main() { 

    double sum, v;
    sum = 0;
    //Scan for a float and print the cumulative sum
    while(scanf("%lf", &v) == 1) {
        printf("\t%.2f\n", sum += v);
    }

}
