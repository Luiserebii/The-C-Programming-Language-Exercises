#include <stdio.h>

int rand(void);
void srand(unsigned int seed);

int main() {

    int n;
    n = rand();
    printf("Random number: %d\n", n);

}

unsigned long int next = 1;

//Generates a psuedo-random number
int rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

//Sets seed for rand(), held in next
void srand(unsigned int seed) {
    next = seed;
}
