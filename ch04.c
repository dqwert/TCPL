#include <stdio.h>
#include <ctype.h>


int get_line(char s[], int lim);
int str_index(char source[], char t[]);


/* find all lines matching pattern */
int find_all_matching_lines() {
  const int MAX_LINE = 1000;

  char pattern[] = "ould";      // pattern to search for

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


/* Exercise 4-1. Write the function strindex(s,t) which returns
 * the position of the rightmost occurrence of t in s, or -1 if there is none.
 */
int strindex(char s[], char t) {
  int i, i_max = -1;
  for (i = 0; s[i] != '\0'; ++i) {
    if (s[i] == t) { i_max = i; }
  }
  return i_max;
}


/* Exercise 4-2. Extend atof to handle scientific notation of the form. */
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


/* original atof: convert string s to double */
double atof(char s[]) {
  double val, power;
  int i, sing;

}


/* atoi: convert string s to integer using atof */
int atoi(char s[]) {
  double atof(char s[]);

  return (int) atof(s);
}


int main() {
//  char s[] = "helllllllllo";
//  printf("%d\n", strindex(s, 'l'));
//  printf("%d\n", strindex(s, '0'));

//  test_no_return_function();
  return 0;
}
