#include <stdio.h>
#include <limits.h>


/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various floating-point types.
 */
void print_integer_range();
void print_float_range();


void determine_ranges() {
  print_integer_range();
  print_float_range();
}


void print_integer_range() {
  printf("char\tunsigned:\t%12u\t%12u\n", 0, UCHAR_MAX);
  printf("\t  signed:\t%12d\t%12d\n", CHAR_MIN, CHAR_MAX);
  printf("short\tunsigned:\t%12u\t%12u\n", 0, USHRT_MAX);
  printf("\t  signed:\t%12d\t%12d\n", SHRT_MIN, SHRT_MAX);
  printf("int\tunsigned:\t%12u\t%12u\n", 0, UINT_MAX);
  printf("\t  signed:\t%12d\t%12d\n", INT_MIN, INT_MAX);
  printf("long\tunsigned:\t%12lu\t%12lu\n", 0lu, ULONG_MAX);
  printf("\t  signed:\t%12ld\t%12ld\n", LONG_MIN, LONG_MAX);
  printf("long long\tunsigned:\t%24llu\t%24llu\n", 0llu, ULONG_LONG_MAX);
//  printf("long long   signed:\t%24lld\t%24lld\n", LONG_LONG_MIN, LONG_LONG_MAX);    // obsolete version of LLONG_MIN, LLONG_MAX
  printf("long long\t  signed:\t%24lld\t%24lld\n", LLONG_MIN, LLONG_MAX);
}


void print_float_range() {
  float curr_float = 1.0f, prev_float;
  double curr_double = 1.0, prev_double;

  while (curr_float != 0.0f) {
    prev_float = curr_float;
    curr_float /= 2.0f;
  }
  printf("Minimal positive float =%e\n", prev_float);

  while (curr_double != 0.0f) {
    prev_double = curr_double;
    curr_double /= 2.0f;
  }
  printf("Minimal positive double=%e\n", prev_double);

  curr_float = 1.0f;
  float test_float = 0.0f;

  while (test_float == 0.0f) {
    prev_float = curr_float;
    curr_float *= 1.01f;
    test_float = (test_float + curr_float) - curr_float;
  }
  printf("Maximum positive float =%e\n", prev_float);

  curr_double = 1.0;
  double test_double = 0.0;
  while (test_double == 0.0) {
    prev_double = curr_double;
    curr_double *= 1.01;
    test_double = (test_double + curr_double) - curr_double;
  }
  printf("Maximum positive double=%e\n", prev_double);
}


/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. */
int getline_rewrite(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) == EOF) { break; }
    if (c != '\n') { break; }
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


/* original getline: read a line into s, return length */
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


/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x / 0X)
 * into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
 */
int htoi_(char s[]) {
  if (!s) { return -1; }

  unsigned char sign;

  // remove leading space
  while (s[0] == ' ') { ++s; }

  // handle positive / negative sign
  if (s[0] == '-') {
    sign = 0;
    ++s;
  } else if (s[0] == '+') {
    sign = 1;
    ++s;
  } else {
    sign = 1;
  }

  // handle leading "0x" and "0X"
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) { s += 2; }

  int value = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    value <<= 4;
    char c = s[i];
    if ('0' <= c && c <= '9') {
      value += c - '0';
    } else if ('a' <= c && c <= 'f') {
      value += c - 'a' + 10;
    } else if ('A' <= c && c <= 'F') {
      value += c - 'A' + 10;
    } else if (c == '_' || c == ' ') {
      continue;
    } else {
      return -1;
    }
#ifndef NDEBUG
    printf("value=%d\n", value);
#endif
  }

  return sign ? value : -value;
}


/* Exercise 2-4. Write an alternative version of squeeze(s1,s2)
 * that deletes each character in s1 that matches any character in the string s2.
 */
void squeeze_(char s[], int c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] != c) {
      s[j] = s[i];
      ++j;
    }
  }
  s[j] = '\0';
  // wipe out memory
  while (j < i) { s[j++] = '\0'; }
}


/* original squeeze: delete all c from s */
void squeeze(char s[], int c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}


/* Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
 * where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 * (The standard library function strpbrk does the same job but returns a pointer to the location.)
 */
int any(const char s1[], const char s2[]) {
  int i;
  for (i = 0; s1[i] != '\0'; ++i) {
    for (int j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) { return i; }
    }
  }
  return -1;
}


/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with
 * the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
  unsigned mask = (1 << n) - 1;
  unsigned offset = p + 1 - n;
  return x & (mask << offset) | ((y & mask) << offset);
}


/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 */
unsigned invert(unsigned x, unsigned p, unsigned n) {
  unsigned mask = (1 << n) - 1;
  unsigned offset = p + 1 - n;
  unsigned to_invert = (x & (mask << offset)) >> offset;
  unsigned inverted = (~to_invert & mask) << offset;
  return x & (mask << offset) | inverted;
}


/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
 * to the right by n positions.
 */
unsigned rightrot(unsigned x, unsigned n) {
  const unsigned BYTE_WIDTH = 8;

  unsigned offset = sizeof(x) * BYTE_WIDTH - n;
  return (x >> n) | (x << offset);
}


/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why.
 * Use this observation to write a faster version of bitcount.
 */
// Answer: (x-1) will flip bits from the rightmost to first '1', then & will zero out all the changed bits.
unsigned bitcount_(unsigned x) {
  unsigned b;
  for (b = 0; x != 0; ++b) {
    x &= (x - 1);
  }
  return b;
}


/* original bitcount: count 1 bits in x */
unsigned bitcount(unsigned x) {
  unsigned b;
  for (b = 0; x != 0; x >>= 1) {
    if (x & 01) { ++b; }
  }
  return b;
}


/* Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 */
int lower_(int c) {
  return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}


/* original lower: convert c to lower case; ASCII only */
int lower(int c) {
  if (c >= 'A' && c <= 'Z') { return c - 'A' + 'a'; }
  else { return c; }
}


int main() {
//  determine_ranges();

//  printf("%d", htoi_("  0Xff"));
//  char s[] = "helllo? Hello!";
//  squeeze_(s, 'l');
//  printf("%s", s);

//  for (char c = 'a'; c <= 'z'; ++c) {
//    char s2[1];
//    s2[0] = c;
//    printf("%d, ",   any("abcdefghijklmnopqrstuvwxyz", s2));
//  }

//  printf("%u\n", setbits(0, 8, 8, 255));
//  printf("%u\n", invert(0, 7, 3));
//  printf("%u\n", rightrot(8, 2));

//  printf("[check bitcount_ against bitcount]\n");
//  for (unsigned i = 0; i < 65536; ++i) {
//    if (bitcount_(i) != bitcount(i)) { printf("Error result from input: %u\n", i); }
//  }
//  printf("All testcases passed.\n");

  printf("[check lower_ against lower]\n");
  for (char i = 0; i < CHAR_MAX; ++i) {
    if (lower_(i) != lower(i)) { printf("Error result from input: %u\n", i); }
  }
  printf("All testcases passed.\n");

  return 0;
}
