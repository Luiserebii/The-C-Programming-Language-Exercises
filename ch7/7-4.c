#include <stdio.h>
#include <stdarg.h>

void minscanf(char* fmt, ...);

int main() {
    minscanf("OwO", 10, 20);
}

void minscanf(char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    
    for(int i = 0; i < 2; ++i) {
        printf("n: %d\n", va_arg(ap, int));
    }
}
