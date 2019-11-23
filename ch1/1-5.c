#include <stdio.h>

main() {
    
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;
    //Print heading
    printf("  F      C\n");
    printf("===========\n");
    while (fahr >= lower) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr -= step;
    }

}
