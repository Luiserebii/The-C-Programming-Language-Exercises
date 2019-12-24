#include <stdio.h>
#include <string.h>
#include "buffer.h"

char buffer_str[MAX_LEN][MAX_LINES];

//Pointer to current piece of buffer
char** buffer_curr = buffer_str;
char** buffer_end = buffer_str + MAX_LINES;

void buffer_push(char* line) {
    if(buffer_curr == buffer_end) {
        //Loop over and bring back to beginning
        buffer_curr = buffer_str;
    }

    //Copy in, and advance buffer_curr
    strcpy(*buffer_curr++, line);
}

void buffer_print(int n) {
    char** curr = buffer_curr;
    for(int i = 0; i < n; ++i) {
        //Loop over and bring back to the beginning
        if(curr == buffer_end) {
            curr = buffer_str;
        }
        printf("%s", *curr++);
    }
}
