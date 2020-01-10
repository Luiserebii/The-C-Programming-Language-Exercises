#ifndef POINT_H
#define POINT_H

struct point {
    int x;
    int y;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
void printpoint(struct point p);

#endif
