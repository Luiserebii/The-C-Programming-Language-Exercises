#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upper();
void lower();
void trimFilename(char* s);

int main(int argc, char* argv[]) {
   
    //Trim name for comparison, eliminate / in filepath
    trimFilename(argv[0]);

    if(strcmp("upper", argv[0]) == 0) {
        upper();
    } else if(strcmp("lower", argv[0]) == 0) {
        lower();
    } else {
        fprintf(stderr, "ERROR: %s not a valid name for this program\n", argv[0]);
    }

}

void upper() {
    int c;
    while((c = getchar()) != EOF) {
        putchar(toupper(c));
    }
}

void lower() {
    int c;
    while((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
}

/** 
 * Trims a filename like "./hello" and transforms it into "hello"
 */
void trimFilename(char* s) {
    char* slash;
    //Iterate through, keep a pointer to the last slash
    for(char* it = s; *it; ++it) {
        if(*it == '/') {
            slash = it;
        }
    }
    
    //Finally, copy [slash + 1, end) into the string
    for(++slash; *slash; ++slash) {
        *s++ = *slash;
    }
    //End with null char
    *s = '\0';
}
