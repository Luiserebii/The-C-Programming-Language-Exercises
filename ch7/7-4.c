#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define MAXFORMAT 50

void minscanf(char* fmt, ...);
int isOption(int c);

int main() {
    int day, year;
    char monthname[20];

    int amt = minscanf("%d %s %d", &day, monthname, &year);
    if(amt == 3) {
        printf("Successfully minscanf'd!\n");
        printf("Day: %d\nMonth:%s\nYear:%d\n", day, monthname, year);
    } else {
        fprintf(stderr, "minscanf | Error: Arguments passed are incorrect, only successfully scanned %d args. Please try again.", amt);
    }
}

/* minscanf:  minimal scanf with variable argument list */
void minscanf(char* fmt, ...) {

    va_list ap; //Declare argument pointer
    char* p;

    int* iptr;
    double* dptr;
    char** sval;

    char options[MAXFORMAT];
    char* optionsptr = options;

    char fmtstr[MAXFORMAT];

    va_start(ap, fmt); /* make ap point to 1st unnamed argument */
    //Iterate through chars in formatted string param
    for(p = fmt; *p; ++p) {
        //If it's not a conv. specification, print and skip to next
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        //Iterate over for potential options
        for(++p; !isOption(*p); ++p) {
            //Add char to options buffer
            *optionsptr++ = *p;
        }
        //Switch between the options and print!
        switch(*p) {
            case 'd':
                strcpy(fmtstr, "%");
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                strcat(fmtstr, "d");
                iptr = va_arg(ap, int*);
                scanf(fmtstr, ival);                
                break;
            case 'f':
                strcpy(fmtstr, "%");
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                strcat(fmtstr, "f");
                dptr = va_arg(ap, double*);
                scanf("%f", dval);
                break;
            case 's':
                strcpy(fmtstr, "%");
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                strcat(fmtstr, "s");
                sptr = va_arg(ap, char**);
                printf("Using this format string: %s\n", fmtstr);
                scanf(fmtstr, sval);
                break;
            case 'c':
                strcpy(fmtstr, "%");
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                strcat(fmtstr, "c");
                iptr = va_arg(ap, int*);
                scanf(fmtstr, ival);
                break;
        }

        //Clear options buffer
        *options = '\0';
        optionsptr = options;
    }
    va_end(ap); /* cleanup when done */
}

int isOption(int c) {
    return c == 'd' || c == 'f' || c == 's' || c == 'c';
}