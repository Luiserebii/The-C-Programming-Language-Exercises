#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "keyword.h"
#include "keytab.h"

/* Count C keywords - Pointer version */
int main() {

    char word[MAXWORD];
    struct key* p;
    //Grab each word, if found within keytab, use pointer to key returned
    //to advance count
    while(getword(word, MAXWORD) != EOF) {
        if(isalpha(word[0])) {
            if((p = binsearch(word, keytab, keytab_size)) != NULL) {
                ++p->count;
            }
        }
    }
    //Iterate through each key (by pointer increment), if we have at least one found, print
    for(p = keytab; p < keytab + keytab_size; ++p) {
        if(p->count > 0) {
            printf("%4d %s\n", p->count, p->word);
        }
    }
    return 0;

}
