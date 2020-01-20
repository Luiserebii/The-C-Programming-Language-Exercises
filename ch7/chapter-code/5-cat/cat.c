#include <stdio.h>

void filecopy(FILE* ifp, FILE* ofp);

/* cat:  concatenate files, version 1 */
int main(int argc, char* argv[]) {
    
    FILE *fp; //Declare a FILE pointer

    //If no args passed, just copy standard input
    if(argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while(--argc > 0) {
            //Attempt to open each file passed, and if successful
            if((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                //Copy file to standard out
                filecopy(fp, stdout);
                //Close the file buffer
                fclose(fp);
            }
        }
    }
}

/* filecopy:  copy file ifp to file ofp */
void filecopy(FILE* ifp, FILE* ofp) {
    int c;
    while((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}
