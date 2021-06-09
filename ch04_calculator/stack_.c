#include <stdio.h>

#define MAX_VAL 100

int sp = 0;
double val[MAX_VAL];

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAX_VAL) { val[sp++] = f; }
  else { printf("Error: stack full, can't push %g\n", f); }
}


/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) { return val[--sp];}
  else {
    printf("Error: stack empty\n");
    return 0.0;
  }
}
