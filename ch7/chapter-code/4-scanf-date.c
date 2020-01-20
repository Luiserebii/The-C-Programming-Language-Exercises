#include <stdio.h>

int getLine(char s[], int lim);

int main() {
    
    int day, month, year;
    char monthname[20];

    char line[1000];
    //Recommended to obtain line first, process after
    while(getLine(line, sizeof(line)) > 0) {
        //If sscanf matches the string obtained, print as valid
        if(sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
            printf("valid: %s\n", line);
        } else if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
            printf("valid: %s\n", line);
        } else {
            printf("invalid: %s\n", line);
        }
    }

}

int getLine(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
