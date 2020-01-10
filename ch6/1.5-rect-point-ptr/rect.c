#include "rect.h"
#include "point.h"
#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int ptinrect(struct point* p, struct rect* r) {
    return p->x >= r->pt1.x && p->x < r->pt2.x
        && p->y >= r->pt1.y && p->y < r->pt2.y;
}

struct rect canonrect(struct rect* r) {
    struct rect temp;

    temp.pt1.x = min(r->pt1.x, r->pt2.x);
    temp.pt1.y = min(r->pt1.y, r->pt2.y);
    temp.pt2.x = max(r->pt1.x, r->pt2.x);
    temp.pt2.y = max(r->pt1.y, r->pt2.y);
}

void printrect(struct rect* r) {
    printf("\nPrinting rect:\n==================\n\n");
    printpoint(&r->pt1);
    printpoint(&r->pt2);
    putchar('\n');
}
