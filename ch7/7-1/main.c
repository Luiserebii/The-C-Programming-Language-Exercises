#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upper();
void lower();

int main(int argc, char* argv[]) {
    
    if(strcmp("upper", argv[0]) == 0) {
        upper();
    } else if(strcmp("lower", argv[0]) == 0) {
        lower();
    } else {
        fprintf(stderr, "ERROR: %s not a valid name for this program", argv[0]);
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
