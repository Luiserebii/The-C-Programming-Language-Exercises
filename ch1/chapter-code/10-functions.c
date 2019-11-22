#include <stdio.h>

int power(int m, int n);

main() {

    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
    return 0;
}

//Raise base to the nth power
int power(int base, int n) {

    int p;
    //Call by value default allows us to
    //manipulate n, as n is simply a copy - 
    //a temporary variable
    for (p = 1; n > 0; --n) {
        p = p * base;
    }
    return p;
}
/*******************************
 * 1st version of function

//Raise base to the nth power
int power(int base, int n) {

    //Declare vars, one for iteration
    //other to hold power result
    int i, p;
    p = 1;

    //Multiply recursively until hit n
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    return p;
}
*/
