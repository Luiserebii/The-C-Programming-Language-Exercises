#ifndef KEYWORD_H
#define KEYWORD_H

#define MAXWORD 100

struct key {
    char* word;
    int count;
};

int getword(char* word, int lim);
int binsearch(char* word, struct key tab[], int n);

#endif
