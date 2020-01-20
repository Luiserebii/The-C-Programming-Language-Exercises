#include <stdio.h>
#include <string.h>

char* f_gets(char* s, int n, FILE* iop);
int f_puts(char* s, FILE* iop);
int get_line(char* line, int max);

int main() {

    char line[1000];
    while(get_line(line, 1000)) {
        printf("Hey, these file-specific I/O functions (fgets, fputs, fgets) are actually pretty neat\n%s\n", line);
    }
}

/* fgets:  get at most n chars from iop */
char* f_gets(char* s, int n, FILE* iop) {
    register int c;
    register char* cs;
    cs = s;
    
    //While we have not reached max char limit and have stuff to grab from stream
    while(--n > 0 && (c = getc(iop)) != EOF) {
        //Add to char*, and if we hit a newline, break
        if((*cs++ = c) == '\n') {
            break;
        }
    }
    //End with null character
    *cs = '\0';

    //Return NULL if we read nothing but EOF, char* otherwise
    return (c == EOF && cs == s) ? NULL : s;
}

/* fputs:  put string s on file iop */
int f_puts(char* s, FILE* iop) {
    int c;
    //Iterate through each char and putc into file
    while(c = *s++) {
        putc(c, iop);
    }
    //Return EOF based on error, 0 otherwise
    return ferror(iop) ? EOF : 0;
}

/* getline:  read a line, return length */
int get_line(char* line, int max) {
    //If we fail to read anything with fgets, return 0
    if(f_gets(line, max, stdin) == NULL) {
        return 0;
    } else {
        //Otherwise, return the size
        return strlen(line);
    }
}
