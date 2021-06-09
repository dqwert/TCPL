#include <stdio.h>

#define BUFFER_SIZE 100


char buffer[BUFFER_SIZE];
int i_buf = 0;                  // next free position in buffer


int getch(void) {
  return (i_buf > 0) ? buffer[--i_buf] : getchar();
}


void ungetch(int c) {
  if (i_buf >= BUFFER_SIZE) { printf("Error[ungetch]: too many characters\n"); }
  else buffer[i_buf++] = c;
}
