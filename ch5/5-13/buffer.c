#include <stdio.h>
#include <string.h>
#include"buffer.h"

char* lines[MAX_LINES];

//Pointer to current piece of buffer
static char* buffer_curr = lines;
static char* buffer_end = lines[MAX_LINES] + 1;

void buffer_push(char* line) {
    if(buffer_curr == buffer_end) {
        //Loop over and bring back to beginning
        buffer_curr = lines;
    }

    //Copy in, and advance buffer_curr
    strcpy(buffer_curr++, line);
}

