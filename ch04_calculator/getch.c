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


// Exercise 4-7 began
void ungets(char s[]) {
  int i_buf_backup = i_buf;
  char c;
  for (int i = 0; s[i] != '\0'; ++i) {
    if (i_buf >= BUFFER_SIZE) {
      printf("Error[ungets]: string to long, ungets failed, buffer unsafely restored\n");
      i_buf = i_buf_backup;
      return;
    }
    else buffer[i_buf++] = c;
  }
}
// Exercise 4-7 end
