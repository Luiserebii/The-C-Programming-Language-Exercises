#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void processFind(FILE* stream, char* pattern, int limit, int number);
int getLine(char s[], int lim);

int main(int argc, char* argv[]) {

    int c, except = 0, number = 0, found = 0;

    //While we have arguments (which leads with a flag)
    while(--argc > 0 && (*++argv)[0] == '-') {
        //For each flag arg we can find
        //Note that this expression is different;
        //this incrememnts argv[0], whereas the above
        //increments argv
        while(c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    fprintf(stderr, "find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    //Apply logic depending on whether we are passed no arguments,
    //one argument (use standard input), or multiple (assume files)
    if(argc == 0) {
        printf("Usage: find -x -n pattern\n");
    } else if(argc == 1){
        processFind(stdout, *argv, MAXLINE, number);
    } else {
        
    }
    return found;
}

void processFind(FILE* stream, char* pattern, int limit, int number) {
    long lineno = 0;
    char line[MAXLINE];
    while(getLine(stream, line, limit) > 0) {
        ++lineno;
        //If the pattern passed (which is now at *argv) is found within line
        if((strstr(line, pattern) != NULL) != except) {
            //If number flag is valid, print lineno found
            if(number) {
                printf("%ld:", lineno);
            }
            printf("%s", line);
            ++found;
        }
    }
}

int getLine(FILE* stream, char s[], int lim) {
    return (fgets(line, lim, stream) == NULL) ? 0 : strlen(line);
}
