#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "calc.h"
#include "varstack.h"


#define MAXOP 100
#define NUMBER '0'
#define SIN '$'
#define EXP '@'
#define POW '^'
#define SETVAR '='

int getop(char []);
void push(double);
double pop(void);

int main() {
    int type;
    double op1, op2;
    char s[MAXOP];
    //Holding variables here for usage
    double vars[CHAR_MAX];

    //While we can get an operator
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                //Push numbers onto the stack
                push(atof(s));
                break;
            case VARIABLE:
                //Push variables onto the stack
                pushVar(s[0]);
                //Push the variable val onto the value stack
                //This is done for convenience, so that we don't have some
                //sort of "nextVal()" function we might wrap around pop()
                //Minimizing complexity here
                //
                //NOTE: This will result in setting a garbage value on the
                //first try
                push(vars[s[0]]);
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
            case SETVAR:
                printf("Setting a var...\n");
                vars[popVar()] = pop();
                //Clearing the var value pushed onto the value stack
                pop();
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
