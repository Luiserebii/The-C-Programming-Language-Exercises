#include <stdio.h>
#include <string.h>
#include "buffer.h"

char* lines[MAX_LINES];

//Pointer to current piece of buffer
char** buffer_curr = lines;
char** buffer_end = lines + 1;

void buffer_push(char* line) {
    if(buffer_curr == buffer_end) {
        //Loop over and bring back to beginning
        buffer_curr = lines;
    }

    //Copy in, and advance buffer_curr
    strcpy(*buffer_curr++, line);
}
