#include <stdio.h>

#define MAX_LENGTH 10
#define TRUE 1
#define FALSE 0

main() {

    int lengthCount[MAX_LENGTH + 1];
    //Initialize all of array to 0
    for(int i = 0; i < MAX_LENGTH + 1; ++i) {
        lengthCount[i] = 0;
    }

    int c;
    int isInWord = FALSE;
    int wordLength = 0;
    while((c = getchar()) != EOF) {
        if(c != ' ' && c != '\n' && c != '\t') {
            isInWord = TRUE;
            ++wordLength;
        } else {
            //Action depends on whether is in word or not for collecting
            if(isInWord == TRUE) {
                //Write length, since we just left
                if(wordLength <= MAX_LENGTH) {
                    ++lengthCount[wordLength]; 
                }
                isInWord = FALSE;
                wordLength = 0;
            }
        }
    }

    for(int i = 0; i < MAX_LENGTH + 1; ++i) {
        printf("%d: %d\n", i, lengthCount[i]);
    }

    //Write histogram
    //Obtain highest occurence found
    int highest = 0;
    for(int i = 0; i < MAX_LENGTH + 1; ++i) {
        if(lengthCount[i] > highest) highest = lengthCount[i];
    }
    //Now, create histogram:

    //Iterate through downwards, from the highest
    for(int i = highest; i > 0; --i) {
        //For each row, 
        //iterate through each array index
        for(int index = 0; index < MAX_LENGTH + 1; ++index) {
            //If this column value is less than row we're on
            if(lengthCount[index] < i) {
                //Print a blank
                putchar('-');
            } else {
                putchar('x');
            }
        }
        //At the end of the row, place a newline
        putchar('\n');
    }
}
