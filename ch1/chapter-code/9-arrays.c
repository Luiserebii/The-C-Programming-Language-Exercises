#include <stdio.h>

main() {

    //Declare vars for counting digits, whitespace,
    //and other chars found
    int c, i, nwhite, nother;

    //Array to hold digit occurences
    int ndigit[10];

    nwhite = nother = 0;
    //Initialize all array vals to 0
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        //Check to see if integer val char is within
        //range of digits
        if(c >= '0' && c <= '9') {
            //Increment at appropriate part of the arr
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            //Increment whitespace
            ++nwhite;
        } else {
            //Otherwise, it's some other char
            ++nother;
        }
    }
    //Finally, print results
    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", whitespace = %d, other = %d\n", 
            nwhite, nother);

}
