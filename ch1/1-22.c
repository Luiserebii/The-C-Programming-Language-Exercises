#include <stdio.h>

#define MAX_SIZE 1000

int get_line(char a[]);
void printFold(char c[], int size, int limit);

main() {

    char input[MAX_SIZE];
    int len;
    while((len = get_line(input)) != 0) {
        //Note; this also prints
        printFold(input, len, 20);
    }

}

int get_line(char a[]) {
    int c;
    int i;
    for(i = 0; i < MAX_SIZE - 1 && ((c = getchar()) != '\n') && c != EOF; ++i) {
        a[i] = c;
    }
    if(c == '\n') {
        a[i] = c;
        ++i;
    }

    a[i] = '\0';
    return i;
}

void printFold(char c[], int size, int limit) {
    int latest = 0;
    for(int i = 0; i < size; ++i) {
        if(c[i] != ' ') {
            if(latest <= limit) {
                putchar(c[i]);
                ++latest;
            } else {
                printf("-\n");
                latest = 0;
            }
        } else if(latest != 0) {
            putchar(c[i]);
            ++latest;
        }
    }
}
