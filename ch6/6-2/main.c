#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    //Options
    int firstn = 3;

    while(*(++argv)) {
        //Check if current one is a flag
        if(argv[0][0] == '-') {
            //Switch between options
            switch(argv[0][1]) {
                //-n specified: numbers of chars identical in the first n requested
                case 'n':
                    //Advance to next one
                    ++argv;
                    //Grab next
                    firstn = atoi(*(++argv));
                    printf("Passed: %d\n", firstn);

                    break;
                default:
                    printf("Invalid flag -%c\n", argv[0][1]);
                    break;
            }

        }
        
    }
}
