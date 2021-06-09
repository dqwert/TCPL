#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'


void push(double);
double pop(void);
int getop(char []);


void reverse_polish_calculator() {
  const int MAXOP = 100;

  int type;
  double op2;
  char s[MAXOP];

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
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("Error: unknown command %s\n", s);
        break;
    }
  }
}


int getch(void);
void ungetch(int);


/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {}

  s[1] = '\0';
  if (!isdigit(c) && c != '.') { return c; }
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch())) {}
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch())) {}
  }
  s[i] = '\0';
  if (c != EOF) { ungetch(c); }
  return NUMBER;
}


int main(void) {
  reverse_polish_calculator();
}
