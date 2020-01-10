#include <stdio.h>

#include "point.h"
#include "rect.h"

int main() {
    
    //Test creating a point
    struct point p1 = makepoint(10, 20);
    struct point p2 = makepoint(20, 100);

    //Attempt printing points
    printpoint(&p1);
    printpoint(&p2);

    //Print the sum of the points
    struct point sum = addpoint(&p1, &p2);
    printpoint(&sum);
    
    /**
     * Note that this line below will not work, as we get:
     *
     * main.c: In function ‘main’:
     * main.c:19:16: error: lvalue required as unary ‘&’ operand
     *      printpoint(&(addpoint(&p1, &p2)));
     *                      ^
     **/
    //printpoint(&(addpoint(&p1, &p2)));

/*
    //Test creating a rect (using intializer list)
    struct rect r1 = { p1, p2 };

    //Print rect
    printrect(r1);

    printf("Is (0,0) in r1? | %d\n", ptinrect(makepoint(0, 0), r1));
    printf("Is (15,50) in r1? | %d\n", ptinrect(makepoint(15, 50), r1));
    printf("Is (50,50) in r1? | %d\n", ptinrect(makepoint(50, 50), r1));
*/}
