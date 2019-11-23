#include <stdio.h>

#define MAX_LENGTH 10
#define TRUE 1
#define FALSE 0

main() {

    int lengthCount[MAX_LENGTH + 1];

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
}
