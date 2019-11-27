#include <stdio.h>
#include <limits.h>

int main() {

    printf("Printing all ranges of epic memes\n\n");

    printf("SIGNED: \n\n");
    printf("char: %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("short: %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d - %d\n", INT_MIN, INT_MAX);
    printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);
    putchar('\n');

    printf("UNSIGNED: \n\n");
    printf("char: 0 - %u\n", UCHAR_MAX);
    printf("short: 0 - %u\n", USHRT_MAX);
    printf("int: 0 - %u\n", UINT_MAX);
    printf("long: 0 - %lu\n", ULONG_MAX);
}
