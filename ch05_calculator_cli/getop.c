#include <stdio.h>
#include <ctype.h>

#include "calc.h"


/* getop: get next character or numeric operand */
int getop(char s[]) {
  if (!isdigit(s[0]) && s[0] != '.') {
    s[1] = '\0';
    return s[0];
  }

  int i = -1;
  while (isdigit(s[++i])) {}
  if (s[i] == '.') {
    while (isdigit(s[++i])) {}
  }
  s[i] = '\0';
  return NUMBER;
}
