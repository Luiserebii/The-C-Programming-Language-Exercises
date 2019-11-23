#include <stdio.h>

main() {
 
//  This line below will fail to run!
//
//  printf(getchar() != EOF);
//
//  Looks like the only way to do this, is by 
//  formatting it, can't just throw vars in

    int c;
    while(1) {
        printf("%d\n", (c = getchar()) != EOF);
        //Stop at EOF
        if(c == EOF) {
            break;
        }
    }
}
