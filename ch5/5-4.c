#include <stdio.h>

int strend(char* s, char* t);
int strlen(char* s);

int main() {
    
    char* a = "OwO";
    char* b = "uwu";
    char* c = "OwOuwu";
}

int strend(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    if(lenT > lenS) {
        return 0;
    }
    //Advance s to place where t will fit
    *s += lenS - lenT;
    //While equal, advance
    while(*s++ == *t++)
        ;
    //If we landed at the end, then great, we're equal;
    if(*s == '\0') {
        return 1;
    } else {
        return 0;
    }


}

int strlen(char* s) {
    int i = 0;
    while(*s++) {
        ++i;
    }
    return i;
}
