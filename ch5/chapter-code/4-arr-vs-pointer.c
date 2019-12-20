/**
 * Comparing the styles of various functions,
 * using arrays, and using pointers
 */

//Using arrays
void strcpy(char *s, char *t) {
    int i = 0;
    while((s[i] = t[i]) != '\0') {
        ++i;
    }
}
//Pointer, 1st kind
void strcpy(char *s, char *t) {
    while((*s++ = *t++) != '\0')
        ;
}

//Pointer, 2nd kind
//
//This function takes advantage of '\0' as 0;
//and 0 as false
//
//An initially appearing cryptic C idiom that
//is used frequently!
void strcpy(char *s, char *t) {
    while(*s++ = *t++)
        ;
}

/**
 * strcmp(char *s, char *t)
 */
//Using arrays
int strcmp(char *s, char *t) {
    int i;
    for(i = 0; s[i] == t[i]; ++i) {
        if(s[i] == '\0') {
            return 0;
        }
    }
    return s[i] - t[i];
}

//Pointers
int strcmp(char *s, char *t) {
    for( ; *s == *t; ++s, ++t) {
        if(*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}
