#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "word.h"

struct tnode {
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* addtree(struct tnode* p, char* w);
void treeprint(struct tnode* p);

struct tnode* talloc();
char* str_dup(char* s);

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

/* addtree:   add a node with w, at or below p */
struct tnode* addtree(struct tnode* p, char* w) {
    int cond;
    //If null, then new word has arrived to set
    if(p == NULL) {
        p = talloc(); //Allocate a new node
        p->word = str_dup(w); //Duplicate the word, set newly allocated string pointer
        p->count = 1;
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0) {
        //We found a word, so increment the count
        ++p->count;
    } else if(cond < 0) {
        //Recurse into the left subtree, as less than
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

/* treeprint:   in-order print of tree p */
void treeprint(struct tnode* p) {
    //Recursive print; if node is not null, attempt to print it and its children
    if(p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc:   make a node */
struct tnode* talloc() {
    return (struct tnode*) malloc(sizeof(struct tnode));
}

/* str_dup:   create a dynamically-allocated string duplicate of s */
char* str_dup(char* s) {
    char* p;
    //malloc for our string; +1 to account for '\0'
    p = (char*) malloc(strlen(s) + 1);
    //Assuming we malloc'd successfully, copy over
    if(p != NULL) {
        strcpy(p, s);
    }
    return p;
}
