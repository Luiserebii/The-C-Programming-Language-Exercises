#include <stdio.h>

main() {

    //Declare fahr/celsius for printing
    int fahr, celsius;
    int lower, upper, step;

    //Lower and upper limits of table
    lower = 0; 
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        //Generate celsius from fahr
        celsius = 5 * (fahr-32) / 9;
        //Print lines
        printf("%d\t%d\n", fahr, celsius);
        //Step forward
        fahr = fahr + step;
    }
    
}
