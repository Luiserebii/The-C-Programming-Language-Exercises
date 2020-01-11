#ifndef BINTREE_H
#define BINTREE_H

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

#endif
