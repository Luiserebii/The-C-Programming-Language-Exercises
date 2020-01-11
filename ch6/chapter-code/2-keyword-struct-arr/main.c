#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "keyword.h"
#include "keytab.h"

/* Count C keywords */
int main() {
    int n;
    char word[MAXWORD];
    //Grab each word, if found within keytab, use location found
    //to advance count
    while(getword(word, MAXWORD) != EOF) {
        if(isalpha(word[0])) {
            if((n = binsearch(word, keytab, /*NKEYS*/keytab_size)) >= 0) {
                ++keytab[n].count;
            }
        }
    }
    //Iterate through each key, if we have at least one found, print
    for(n = 0; n < /*NKEYS*/keytab_size; ++n) {
        if(keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;

}
