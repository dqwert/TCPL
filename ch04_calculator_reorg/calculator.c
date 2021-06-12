#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "calc.h"


void reverse_polish_calculator(void) {
  const int MAXOP = 100;

  int type;
  double op2;
  char s[MAXOP];

// Exercise 4-6 begins
  double last_printed = 0.0;
// Exercise 4-6 ends

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
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
        if (op2 != 0.0) { push(pop() / op2); }
        else { printf("Error: zero divisor"); }
        break;
      case '\n':
        printf("\t%.8g\n",  top());     // change pop() to pop()
        last_printed = top();
        break;

// Exercise 4-3 begins
      case '%':
        op2 = pop();
        if (op2 != 0.0) { push((int) pop() % (int) op2); }
        else { printf("Error: zero divisor"); }
        break;
// Exercise 4-3 ends

// Exercise 4-4 begins
      case 'T':
        printf("\t%g\n", top());
        last_printed = top();
        getchar();
        break;
      case 'A':
        print_stack();
        last_printed = top();
        getchar();
        break;
      case 'S':
        swap_top_two();
        break;
      case 'D':
        dup_top();
        break;
      case 'C':
        clear();
        getchar();
        break;
// Exercise 4-4 ends

// Exercise 4-5 begins
      case 's':
        push(sin(pop()));
        break;
      case 'c':
        push(cos(pop()));
        break;
      case 't':
        push(tan(pop()));
        break;

      case 'e':
        push(exp(pop()));
        break;
      case 'p':
        op2 = pop();
        push(pow(pop(), op2));
        break;
// Exercise 4-5 ends


      default:
        printf("Error: unknown command %s\n", s);
        break;
    }
  }
}
