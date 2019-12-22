#include <stdio.h>
void print(int* owo);

int main() {
    
    int cock[] = {0, 10, 20, 30, 40, 111};
    print(cock + 1); 
}

void print(int* owo) {
    while(*owo != 111) {
        printf("COCK: %d\n", *owo++);
    }
}
