int main() {


}

//Delete all char c from string s
void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

//Concatenate char[] t to end of char[] s
void strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') {
        ++i;
    }
    while(s[i++] = t[j++] != '\0')
        ;
}
