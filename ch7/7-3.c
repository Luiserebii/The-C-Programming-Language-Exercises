#include <stdio.h>
#include <stdarg.h>

#define MAXFORMAT 50

void minprintf(char* fmt, ...);
int isOption(int c);

int main() {
    minprintf("%.10s\n", "hello, world");
}

/* minprintf:  minimal printf with variable argument list */
void minprintf(char* fmt, ...) {

    va_list ap; //Declare argument pointer
    char* p;
    char* sval;
    int ival;
    double dval;

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
            printf("Adding %c to buffer\n", *p);
        }
        //Switch between the options and print!
        switch(*p) {
            case 'd':
                fmtstr = "%d";
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                ival = va_arg(ap, int);
                printf(fmtstr, ival);                
                break;
            case 'f':
                fmtstr = "%f";
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                fmtstr = "%s";
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                sval = va_arg(ap, char*);
                printf(fmtstr, sval);
                break;
            case 'c':
                fmtstr = "%c";
                //Add options, if there are any
                if(*options) {
                    strcat(fmtstr, options);
                }
                ival = va_arg(ap, int);
                printf(fmtstr, ival);
                break;
        }

        //Clear options bugger
        *options = '\0';
        optionsptr = options;
    }
    va_end(ap); /* cleanup when done */
}

int isOption(int c) {
    return c == 'd' || c == 'f' || c == 's' || c == 'c';
}
