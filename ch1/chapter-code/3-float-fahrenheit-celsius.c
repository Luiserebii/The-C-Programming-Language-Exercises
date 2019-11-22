#include <stdio.h>

main() {

    //Declare fahr/celsius for printing
    float fahr, celsius;
    int lower, upper, step;

    //Lower and upper limits of table
    lower = 0; 
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        //Generate celsius from fahr
        celsius = (5.0/9.0) * (fahr-32.0);
        //Print lines

        //Using %f instead of %d for printf specification
        //%x.yf, where:
        //x is num of characters wide
        //y is num of chars after decimal point
        printf("%3.0f %6.1f\n", fahr, celsius);
        //Step forward
        fahr = fahr + step;
    }
    
}
