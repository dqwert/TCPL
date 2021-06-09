#include <stdio.h>
#include <ctype.h>


int get_line(char s[], int lim);
int str_index(char source[], char t[]);


/* find all lines matching pattern */
int find_all_matching_lines(void) {
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


dummy(void) {}


void test_no_return_function(void) {
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


/* Exercise 4-2. Extend atof to handle scientific notation of the form `123.45e-6`
 * where a floating-point number may be followed by e or E and an optionally signed exponent. */
double atof_(char * s) {
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

  if (s[i++] == 'e') {
    int exponent_is_positive = (s[i] == '-') ? 0 : 1;
    if (s[i] == '+' || s[i] == '-') { ++s; }

    int exponent;
    for (exponent = 0; isdigit(s[i]); ++i) {
      exponent = exponent * 10 + (s[i] - '0');
    }
    while (exponent--) {
      power *= exponent_is_positive ? 0.1 : 10;
    }
  }

  return sign * val / power;
}


/* original atof: convert string s to double */
double atof(char s[]) {
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
int atoi_(char s[]) {
  return (int) atof(s);
}


/* Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator.
 * Add the modulus (%) operator and provisions for negative numbers.
 */
// see ch04_calculator


/* Exercise 4-4. Add the commands to print the top elements of the stack without popping,
 * to duplicate it, and to swap the top two elements. Add a command to clear the stack.
 */


int main(void) {
//  char s[] = "helllllllllo";
//  printf("%d\n", strindex(s, 'l'));
//  printf("%d\n", strindex(s, '0'));

//  test_no_return_function();

  printf("%f\n", atof("123.45"));
  printf("%f\n", atof_("123.45"));

  printf("%f\n", atof("123.45e6"));
  printf("%f\n", atof_("123.45e6"));

  printf("%f\n", atof("123.45e-6"));
  printf("%f\n", atof_("123.45e-6"));

  return 0;
}
