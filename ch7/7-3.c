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
                ival = va_arg(ap, int); //Obtain current argument based on type, and increment to next pointer
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                printf("WE'RE HERE???");
                for(sval = va_arg(ap, char*); *sval; ++sval) {
                    putchar(*sval);
                }
                //Print options (as test)
                printf("| OPTIONS: %s |", options);
                //Clear options buffer
                *options = '\0';
                optionsptr = options;
                break;
            case 'c':
                ival = va_arg(ap, int);
                putchar(ival);
                break;
        }
    }
    va_end(ap); /* cleanup when done */
}

int isOption(int c) {
    return c == 'd' || c == 'f' || c == 's' || c == 'c';
}
