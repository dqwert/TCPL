#include <stdio.h>
#include <ctype.h>


int getch(void);
void ungetch(int);


/* Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back on the input.
 */
int getint_(int *pn) {
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
int getint(int *pn) {
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
  while (*s) { ++s; ++s_len; }
  while (*t) { ++t; ++t_len; }
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


/* Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing.
 * Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */


int main(void) {
//  char s[] = "Hello, \0space_for_concatenation";
//  char t[] = "world!";
//  printf("%s\n", s);
//  str_cat_(s, t);
//  printf("%s\n", s);
//
//  if (str_end(s, t)) {
//    printf("t occurs at the end of the string s\n");
//  } else {
//    printf("t does not occur at the end of the string s\n");
//  }

}
