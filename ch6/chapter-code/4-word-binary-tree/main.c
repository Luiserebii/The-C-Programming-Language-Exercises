#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
}

struct tnode* addtree(struct tnode* p, char* w);
void treeprint(struct tnode* p);

struct tnode* talloc();
char* strdup(char* s);

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

/* addtree:   add a node with w, at or below p */
struct tnode* addnode(struct tnode* p, char* w) {
    int cond;
    //If null, then new word has arrived to set
    if(p == NULL) {
        p = talloc(); //Allocate a new node
        p->word = strdup(w); //Duplicate the word, set newly allocated string pointer
        p->count = 1;
        p->left = p->right = NULL;
    }
}
