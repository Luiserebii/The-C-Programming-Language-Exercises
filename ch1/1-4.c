#include <stdio.h>

main() {

    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    //Headline
    printf("  C      F\n");
    printf("============\n");
    for(celsius = lower; celsius <= upper; celsius += step) {
        fahr = ((celsius * 9) / 5.0) + 32;
        printf("%3.0f   %6.1f\n", celsius, fahr);
    }

}
