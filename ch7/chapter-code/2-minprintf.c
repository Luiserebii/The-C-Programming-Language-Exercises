#include <stdio.h>
#include <stdarg.h>

void minprintf(char* fmt, ...);

int main() {
    minprintf("%d OwO %s UwU %f\n", 10, "huh", 290.19);
}


/* minprintf:  minimal printf with variable argument list */
void minprintf(char* fmt, ...) {

    va_list ap; //Declare argument pointer
    char* p;
    char* sval;
    int ival;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed argument */
    //Iterate through chars in formatted string param
    for(p = fmt; *p; ++p) {
        //If it's not a conv. specification, print and skip to next
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int); //Obtain current argument based on type, and increment to next pointer
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%d", ival);
                break;
            case 's':
                for(sval = va_arg(ap, char*); *sval; ++sval) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* cleanup when done */
}
