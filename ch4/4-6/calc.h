#if !defined(CALC_H) 
#define CALC_H

#define NUMBER '0'
#define VARIABLE '='

void push(double);
double pop(void);
double stacktop(void);
double stackduptop(void);
int stackswaptop(void);
void stackclear(void);

int getop(char []);
int getch(void);
void ungetch(int);

#endif
