#include <stdio.h>

int lower(int c);

int main() {

    char a = 'A';
    char b = 'K';
    char c = 'a';
    printf("%c | lower(): %c\n", a, lower(a));
    printf("%c | lower(): %c\n", b, lower(b));
    printf("%c | lower(): %c\n", c, lower(c));

}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
