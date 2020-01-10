#ifndef RECT_H
#define RECT_H

struct rect {
    struct point pt1;
    struct point pt2;
}

int ptinrect(struct point p, struct rect r);
struct rect canonrect(struct rect r);

#endif
