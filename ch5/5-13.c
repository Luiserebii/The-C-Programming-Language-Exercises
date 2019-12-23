#include <stdio.h>
#include <stdlib.h>

#define LINES_DEFAULT 10

void tail(int lines);

int main(int argc, char* argv[]) {
    
    if(--argc > 1 && (*++argv)[0] == '-') {
        if((*argv)[1] != 'n') {
            printf("Invalid option, usage: tail -n num_lines\n");
            return 1;
        }
        //Grab number of memes
        int lines = atoi(*++argv);
        tail(lines);
        return 0;
    }

    //Call tail with the default number of lines
    tail(LINES_DEFAULT);

}

void tail(int lines) {
    printf("%d\n", lines);
}
