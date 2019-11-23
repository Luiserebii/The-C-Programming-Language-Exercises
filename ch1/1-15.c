#include <stdio.h>

float fahrToCelsius(float fahr);

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
        celsius = fahrToCelsius(fahr);
        //Print lines
        printf("%3.0f %6.1f\n", fahr, celsius);
        //Step forward
        fahr = fahr + step;
    }
    
}

float fahrToCelsius(float fahr) {
    return (5.0/9.0) * (fahr-32.0);
}
