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
// see ch04_calculator/calculator.c


/* Exercise 4-4. Add the commands to print the top elements of the stack without popping,
 * to duplicate it, and to swap the top two elements. Add a command to clear the stack.
 */
// see ch04_calculator/calculator.c


/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4. */
// see ch04_calculator/calculator.c


/* Exercise 4-6. Add commands for handling variables. (It's easy to provide 26 variables with single-letter names.)
 * Add a variable for the most recently printed value.
 */
// see ch04_calculator/calculator.c


/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
 * Should ungets know about buf and bufp, or should it just use ungetch?
 */
// see ch04_calculator/getch.c, if ungetch cannot change, ungets should know buf and bufp.
// NOTE: buf renamed to buffer, bufp renamed to i_buf



/* Exercise 4-8. Suppose that there will never be more than one character of pushback.
 * Modify getch and ungetch accordingly.
 */
// Answer: downgrade the buffer to one int initialized to EOF, eliminate i_buf variable. (not implemented)


/* Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly.
 * Decide what their properties ought to be if an EOF is pushed back, then implement your design.
 */
// Answer: change the char buffer to int buffer. (getch and ungetch already have int return value and parameter)


/* Exercise 4-10. An alternate organization uses getline to read an entire input line;
 * this makes getch and ungetch unnecessary. Revise the calculator to use this approach.
 */
// Not implemented.


/* Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable. */
// Not implemented.


/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive routine.
 */
void printd(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10) { printd(n / 10); }
  putchar(n % 10 + '0');
}


/* Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place. */
// initial call: reverse_recursive(s, 0, sizeof(s) / sizeof(s[0]) - 1);
void reverse_recursive(char s[], int i, int j) {
  if (i <= j) { return; }
  char temp = s[i];
  s[i] = s[j];
  s[j] = temp;
  reverse_recursive(s, ++i, --j);
}


/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.) */
#define swap(t, x, y) \
  t temp = (x);         \
  (x) = (y);              \
  (y) = temp;



int main(void) {
//  char s[] = "helllllo";
//  printf("%d\n", strindex(s, 'l'));
//  printf("%d\n", strindex(s, '0'));

//  test_no_return_function();

//  printf("%f\n", atof("123.45"));
//  printf("%f\n", atof_("123.45"));
//
//  printf("%f\n", atof("123.45e6"));
//  printf("%f\n", atof_("123.45e6"));
//
//  printf("%f\n", atof("123.45e-6"));
//  printf("%f\n", atof_("123.45e-6"));

//  printd(1234123);
//  putchar('\n');

//  char s[] = "0xdeadbeef";
//  reverse_recursive(s, 0, sizeof(s) / sizeof(s[0]) - 1);
//  printf("%s\n", s);

  int x = 0, y = 1;
  swap(int, x, y)         // notice there is no semicolon
  printf("x=%d, y=%d\n", x, y);

  return 0;
}
