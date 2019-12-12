#include <stdio.h>
#define swap(t, x, y) \
    {                 \
        t _temp = x;  \
        x = y;        \
        y = _temp;    \
    }

int main() {
    int x = 0;
    int y = 10;
    printf("x: %d, y: %d\n", x, y);
    swap(int, x, y)
    printf("x: %d, y: %d\n", x, y);
    
}
