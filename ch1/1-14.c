#include <stdio.h>

#define MAX_CHAR 256
#define TRUE 1
#define FALSE 0

main() {

    int lengthCount[MAX_CHAR];
    //Initialize all of array to 0
    for(int i = 0; i < MAX_CHAR; ++i) {
        lengthCount[i] = 0;
    }

    int c;
    int wordLength = 0;
    while((c = getchar()) != EOF) {
        ++lengthCount[c];
    }

    //Write histogram
    //Obtain highest occurence found
    int highest = 0;
    for(int i = 0; i < MAX_CHAR; ++i) {
        if(lengthCount[i] > highest) highest = lengthCount[i];
    }
    //Now, create histogram:

    //Iterate through downwards, from the highest
    for(int i = highest; i > 0; --i) {
        //For each row, 
        //iterate through each array index
        for(int index = 0; index < MAX_CHAR; ++index) {
            //If this column value is less than row we're on, and
            //is not 0
            if(lengthCount[index] != 0) {
                if(lengthCount[index] < i) {
                    //Print a blank
                    putchar('-');
                } else {
                    putchar('x');
                }
            }
        }
        //At the end of the row, place a newline
        putchar('\n');
    }
    //List the chars in the histogram:
    for(int i = 0; i < MAX_CHAR; ++i) {
        if(lengthCount[i] > 0) printf("%d: %c\n", i, i);
    }
}
