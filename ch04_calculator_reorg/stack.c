#include <stdio.h>


#define MAX_VAL 100

static int sp = 0;
static double val[MAX_VAL];


/* push: push f onto value stack */
void push(double f) {
  if (sp < MAX_VAL) { val[sp++] = f; }
  else { printf("Error: stack full, can't push %g\n", f); }
}


// Exercise 4-4 begins

double top(void) {
  if (sp > 0) { return val[sp - 1]; }
  else {
    printf("Error: stack empty\n");
    return 0.0;
  }
}


/* pop: pop and return top value from stack */
double pop(void) {
  double res = top();
  --sp;
  return res;
}


void dup_top(void) {
  push(top());
}


void print_stack(void) {
  printf("\t");
  if (sp > 0) {
    for (int i = 0; i < sp; ++i) {
      printf("%g, ", val[i]);
    }
  } else {
    printf("[empty stack]");
  }

  printf("\n");
}


void swap_top_two(void) {
  if (sp < 2) { printf("Error[swap_top_two]: elements not enough\n"); }
  double temp = val[sp - 1];
  val[sp - 1] = val[sp - 2];
  val[sp - 2] = temp;
}


void clear(void) {
  // do safe clear
  while (sp > 0) {
    val[sp - 1] = '\0';
    --sp;
  }
}

// Exercise 4-4 ends
