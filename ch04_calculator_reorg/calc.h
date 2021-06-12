#ifndef TCPL_CALC_H
#define TCPL_CALC_H

#define NUMBER '0'

void reverse_polish_calculator(void);

void push(double);
double top(void);
double pop(void);
void dup_top(void);
void print_stack(void);
void swap_top_two(void);
void clear(void);

int getop(char []);

int getch(void);
void ungetch(int);

#endif //TCPL_CALC_H
