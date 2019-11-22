#include <stdio.h>

main() {

    double nc;
    for(nc = 0; getchar() != EOF; ++nc)
        ; //Empty body; we therefore use semicolon as null statement (!!!)
    printf("%.0f\n", nc);
}


/******************
 * 1st version

#include <stdio.h>

main() {
    
    //Declare
    long nc;
    //Define
    nc = 0;
    //As long as we're getting chars, increment the count
    while(getchar() != EOF) {
        ++nc;
    }
    //Print the count
    printf("%ld\n", nc);

} */
