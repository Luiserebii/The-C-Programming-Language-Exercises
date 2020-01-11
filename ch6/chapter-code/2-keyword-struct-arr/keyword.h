#ifndef KEYWORD_H
#define KEYWORD_H

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key {
    char* word;
    int count;
};

extern struct key keytab[];

int getword(char* word, int lim);
int binsearch(char* word, struct key tab[], int n);

#endif
