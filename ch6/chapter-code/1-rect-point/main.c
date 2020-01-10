#include <stdio.h>

#include "point.h"
#include "rect.h"

int main() {
    
    //Test creating a point
    struct point p1 = makepoint(10, 20);
    struct point p2 = makepoint(20, 100);

    //Attempt printing points
    printpoint(p1);
    printpoint(p2);

    //Print the sum of the points
    printpoint(addpoint(p1, p2));

    //Test creating a rect (using intializer list)
    struct rect r1 = { p1, p2 };

    //Print rect
    printrect(r1);

}
