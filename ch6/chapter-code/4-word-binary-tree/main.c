#include <stdio.h>
#include <ctype.h>

#include "word.h"
#include "bintree.h"

/* Word Frequency count using binary tree */
int main() {
    
    struct tnode* root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if(isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0; 
}
