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
