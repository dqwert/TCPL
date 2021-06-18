#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int getch(void);

void ungetch(int);


/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back on the input.
 */
int getint_(int * pn) {
  int c, sign;

  while (isspace(c = getch())) {}

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  int has_sign = 0;
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    has_sign = 1;
    c = getch();
  }

  if (!isdigit(c)) {
    ungetch(c);
    if (has_sign) {
      ungetch(sign == -1 ? '-' : '+');
    }
  }

  for (*pn = 0; isdigit(c); c = getch()) { *pn = 10 * *pn + (c - '0'); }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}


/* getint: get next integer from input into *pn */
int getint(int * pn) {
  int c, sign;

  while (isspace(c = getch())) {}

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') { c = getch(); }
  for (*pn = 0; isdigit(c); c = getch()) { *pn = 10 * *pn + (c - '0'); }
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return c;
}


/* Exercise 5-2. Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value?
 */
// Not implemented.


/* Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
 * str_cat(s,t) copies the string t to the end of s.
 */
void str_cat_(char * s, char * t) {
  while (*s) { ++s; }
  while ((*(s++) = *(t++)) != '\0') {}
}


/* str_cat: concatenate t to end of s; s must be big enough */
void str_cat(char * s, char * t) {
  int i = 0, j = 0;

  while (s[i] != '\0') { ++i; }
  while ((s[i++] = t[j++]) != '\0') {}
}


/* Exercise 5-4. Write the function str_end(s,t), which returns 1 if the string t occurs at the end of the string s,
 * and zero otherwise.
 */
int str_end(char * s, char * t) {
  int s_len = 0, t_len = 0;
  while (*s) {
    ++s;
    ++s_len;
  }
  while (*t) {
    ++t;
    ++t_len;
  }
  if (t_len > s_len) { return 0; }

  while (t_len-- >= 0) {
    if (*(s--) != *(t--)) { return 0; }
  }
  return 1;
}


/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
 */
char * str_n_cpy(char * s, const char * t, int n) {
  char * curr = s;
  while (n-- && *curr != '\0') {
    if (*t) { *(curr++) = *(t++); }
    else { *(curr++) = '\0'; }
  }
  return s;
}


void test_str_n_copy() {
  const char* src = "hi";
  char dest[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
  str_n_cpy(dest, src, 5);

  printf("The contents of dest are: ");
  for (int i = 0; i < sizeof(dest) / sizeof(dest[0]); ++i) {
    if (dest[i]) { printf("%c ", dest[i]); }
    else { printf("\\0 "); }
  }
  printf("\n");
}


char * str_n_cat(char * s, char * ct, int n) {
  char * curr = s;

  while (*(curr) != '\0') { ++curr; }
  while (n-- && *ct) { *(curr++) = *(ct++); }

  return s;
}


void test_str_n_cat() {
  char str[50] = "Hello ";
  str_n_cat(str, " Goodbye World!", 3);
  printf("%s\n", str);
}


int str_n_cmp(const char * s, const char * ct, int n) {
  while (n--) {
    if (*s != *ct) { return *s - *ct; }
    ++s;
    ++ct;
  }

  return 0;
}



void format_str_n_cmp_output(const char* lhs, const char* rhs, int sz)
{
  int rc = str_n_cmp(lhs, rhs, sz);
  if(rc == 0)
    printf("First %d chars of [%s] equal [%s]\n", sz, lhs, rhs);
  else if(rc < 0)
    printf("First %d chars of [%s] precede [%s]\n", sz, lhs, rhs);
  else if(rc > 0)
    printf("First %d chars of [%s] follow [%s]\n", sz, lhs, rhs);

}


void test_str_n_cmp() {
  const char* string = "Hello World!";
  format_str_n_cmp_output(string, "Hello!", 5);
  format_str_n_cmp_output(string, "Hello", 10);
  format_str_n_cmp_output(string, "Hello there", 10);
  format_str_n_cmp_output(&"Hello, everybody!"[12], &"Hello, somebody!"[11], 5);
}


/* Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing.
 * Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */
int getline__(char * s, int lim) {
  char * curr = s;
  int c;

  while ((c = getchar()) != EOF && c != '\n' && curr - s < lim - 1) { *(curr++) = c; }

  if (c == '\n') { *(curr++) = c; }

  *curr = '\0';
  return curr - s;
}


/* original getline: read a line into s, return length. */
int getline_(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) { s[i] = c; }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


/* Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster is the program?
 */
// TODO


/* Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage. How much faster is the program?
 */
#define MAXLEN 1000

/* original getline from ch02: read a line into s, return length */
int getline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


// not sure if it's correct
int readlines_(char lines[][MAXLEN], int maxlines) {
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines) { return -1; }
    else {
      line[len - 1] = '\0';
      strcpy(lines[nlines++], line);
    }
  }
  return nlines;
}


/* readlines: read input lines */
int readlines(char * lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = malloc(len)) == NULL) { return -1; }
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

#undef MAXLEN


/* Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect. */
int day_of_year_(int year, int month, int day) {
  if (month < 1 || month > 12) { return -1; }

  char daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

  int i, leap;
  leap = year % 4 == 0&& year % 100 != 0 || year % 400 == 0;

  if (day > daytab[leap][month] || day < 1) { return -1; }  // can put `day < 1` to the front

  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}


void month_day_(int year, int yearday, int *pmonth, int *pday) {
  char daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }

  if (yearday > 31 || yearday < 1) {   // can put `yearday < 1` to the front
    *pmonth = *pday = -1;
    return;
  }

  *pmonth = i;
  *pday = yearday;
}


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
  char daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

  int i, leap;
  leap = year % 4 == 0&& year % 100 != 0 || year % 400 == 0;
  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}


/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  char daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = yearday;
}


int main(void) {
//  char s[] = "Hello, \0space_for_concatenation";
//  char t[] = "world";
//  printf("s=%s\n", s);
//  printf("t=%s\n", s);

//  str_cat_(s, t);
//  printf("s=%s\n", s);
//
//  if (str_end(s, t)) {
//    printf("t occurs at the end of the string s\n");
//  } else {
//    printf("t does not occur at the end of the string s\n");
//  }

//  for (int i = 0; i < sizeof(t) / sizeof(t[0]) + 1; ++i) {
//    printf("n=%d,%s\n", i, str_n_cpy(s, t, i));
//  }

// test_str_n_copy();
// test_str_n_cat();
// test_str_n_cmp();

}
