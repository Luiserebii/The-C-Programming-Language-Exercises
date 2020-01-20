#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE* ifp, FILE* ofp);

/* cat:  concatenate files, version 1 */
int main(int argc, char* argv[]) {
    
    FILE *fp; //Declare a FILE pointer
    char* progname = argv[0]; //Useful to have on hand for error reporting (Imagine a user not knowing which program in the pipe caused the error!)

    //If no args passed, just copy standard input
    if(argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while(--argc > 0) {
            //Attempt to open each file passed, and if fails
            if((fp = fopen(*++argv, "r")) == NULL) {
                //Write error to standard error stream
                fprintf(stderr, "%s can't open %s\n", progname, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if(ferror(stdout)) {
        //stderr for error, once more
        fprintf(stderr, "%s: error writing stdout\n", progname);
        exit(2);
    }
}

/* filecopy:  copy file ifp to file ofp */
void filecopy(FILE* ifp, FILE* ofp) {
    int c;
    while((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}
