#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARNAMES 1000
#define MAX_VARLEN 100

char** processCode(char* varnames[]);
int isType(char* s);
void str_cpy(char* s, char* t);

int main(int argc, char** argv) {
    
    //Options
    int firstn = 3;

    while(*(++argv)) {
        //Check if current one is a flag
        if(argv[0][0] == '-') {
            //Switch between options
            switch(argv[0][1]) {
                //-n specified: numbers of chars identical in the first n requested
                case 'n':
                    //Grab next
                    firstn = atoi(*(++argv));
                    //printf("Passed: %d\n", firstn);
                    break;
                default:
                    printf("Invalid flag -%c\n", argv[0][1]);
                    break;
            }

        }
        
    }

    //Our varname array
    char varnames[MAX_VARNAMES][MAX_VARLEN];

    //Process input
    char** last = processCode(varnames);

    //Print all varnames found
    for(char** c = varnames; c != last; ++c) {
        printf("%s\n", *c);
    }
}

char** processCode(char* varnames[]) {
    int inComment = 0;
    int inString = 0;
    char c;
    //Read until end of file
    while((c = getchar()) != EOF) {
        switch(c) {
            case '/':
                //Grab next
                //NOTE: Perhaps our getch/ungetch buffer is safer for this
                if((c = getchar()) == '*') {
                    inComment = 1;
                }
                break;
            case '*': 
                if(inComment) {
                    //Note that we grab without putting back; dangerous
                    if((c = getchar()) == '/') {
                        inComment = 0;
                    }
                }
                break;
            case '"':
                //Toggle inString
                inString = inString ? 0 : 1;
                break;
            case ' ': {
                if(inComment || inString) {
                    break;
                }
                //Ahhh, darn, do we grab a word here? I guess...
                char buffer[10/*00*/];
                char* b = buffer;
                //Skip over whitespace
                while((*b = getchar()) == ' ')
                    ;
                ++b;

                while((*b = getchar()) != ' ' && *b != EOF && ++b)
                    ;
                if(*b == EOF) {
                    //Just break here if we get EOF
                    return varnames;
                }
                //Close our buffered string
                *b = '\0';
                   printf("This is our first grab: |%s|\n", buffer);
                //Now see if it is a type; for simplicity, we will be 
                //limiting the range to int, float, double, char
                if(isType(buffer)) {
                    //NOTE: We are reusing our buffer here for the name
                    b = buffer;
                    while((*b = getchar()) != ' ' && (isalpha(*b) || *b == '_') && *b != EOF && ++b)
                        ;
                    if(*b == EOF) {
                        //Just break here if we get EOF
                        return varnames;
                    }
                    *b = '\0';
                       printf("This is our second grab: |%s|\n", buffer); 
                    //Finally, ensure that the thing is not a function call
                    char* finalChar = b - 1;
                    if(*finalChar != '(') {
                        //Add the thing
                        str_cpy(*varnames++, buffer);
                    }

                }
                break;
            }
        }
    }
    return varnames;
}

int isType(char* s) {
    return strcmp(s, "int") == 0 || strcmp(s, "float") ||
        strcmp(s, "double") == 0 || strcmp(s, "char") == 0;
}

void str_cpy(char* s, char* t) {
    while(*s++ = *t++)
        ;
}
