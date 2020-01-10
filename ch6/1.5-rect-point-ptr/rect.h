#ifndef RECT_H
#define RECT_H

#include "point.h"

struct rect {
    struct point pt1;
    struct point pt2;
};

int ptinrect(struct point p, struct rect r);
struct rect canonrect(struct rect r);
void printrect(struct rect r);

#endif
