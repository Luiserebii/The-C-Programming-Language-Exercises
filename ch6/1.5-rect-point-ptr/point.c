#include <stdio.h>
#include "point.h"

//Create a point from x and y ints
struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

//Return sum of points
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

//Print point to console
void printpoint(struct point p) {
    printf("Printing a point:\n=====================\n");
    printf("x: %d\n", p.x);
    printf("y: %d\n", p.y);
}
