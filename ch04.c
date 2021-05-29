#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 1000 /* maximum input line length */

int get_line(char line[], int max);
int str_index(char source[], char search_for[]);

char pattern[] = "ould";      // pattern to search for

/* find all lines matching pattern */
int find_all_matching_lines() {
  char line[MAX_LINE];
  int found = 0;

  while (get_line(line, MAX_LINE) > 0) {
    if (str_index(line, pattern) >= 0) {
      printf("%s", line);
      ++found;
    }
  }
  return found;
}


/* get_line: get line into s, return length */
int get_line(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}


/* str_index: return index of t in s, -1 if none */
int str_index(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; ++i) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k) {}
    if (k > 0 && t[k] == '\0') {
      return i;
    }
  }
  return -1;
}


dummy() {}


void test_no_return_function() {
  int i = dummy();
  printf("%d", i);
}


/* atof: convert string s to double */
double atof_(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); ++i) {}
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') { ++i; }
  for (val = 0.0; isdigit(s[i]); ++i) { val = 10.0 * val + (s[i] - '0'); }
  if (s[i] == '.') { ++i; }
  for (power = 1.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  return sign * val / power;
}


/* atoi: convert string s to integer using atof */
int atoi(char s[]) {
  double atof(char s[]);

  return (int) atof(s);
}


int main() {
  test_no_return_function();
  return 0;
}
