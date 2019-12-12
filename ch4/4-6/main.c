#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100
#define NUMBER '0'
#define SIN '$'
#define EXP '@'
#define POW '^'

int getop(char []);
void push(double);
double pop(void);

int main() {
    int type;
    double op1, op2;
    char s[MAXOP];
    //Holding variables here for usage
    char vars[26];

    //While we can get an operator
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                //Push numbers onto the stack
                push(atof(s));
                break;
            case 'T':
                printf("Top of stack: %f\n", stacktop());
                //Intended to skip past next character, expected to be a \n
                getch();
                break;
            case 'D':
                printf("Duplication of top of stack: %f\n", stackduptop());
                getch();
                break;
            case 'S':
                printf("Swapping top two of the stack\n");
                stackswaptop();
                getch();
                break;
            case 'C':
                printf("Clearing the stack...\n");
                stackclear();
                getch();
                break;
            case VARIABLE:
                printf("Setting a var...\n");
                vars[s[0]] = pop();
                break;
            case SIN:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default: 
                printf("error: unknown command %s\n", s);
                break;
        }
    }


}
