#ifndef BUFFER_H
#define BUFFER_H

#define MAX_LINES 50
extern char* buffer_str[MAX_LINES];
extern char** buffer_curr;
extern char** buffer_end;

void buffer_push(char* line);
void buffer_print(int n);

#endif
