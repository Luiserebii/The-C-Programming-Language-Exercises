#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
struct tnode* addtree(struct tnode* p, char* w);
void treeprint(struct tnode* p);
int getword(char*, int);

/* Word Frequency count using binary tree */
int main() {
    
    struct tnode* root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if(!isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0; 
}
