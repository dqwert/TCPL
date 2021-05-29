#include <stdio.h>
#include <limits.h>


void print_integer_range() {
  printf("char\tunsigned:\t%12d\t%12d\n", 0, UCHAR_MAX);
  printf("\t  signed:\t%12d\t%12d\n", CHAR_MIN, CHAR_MAX);
  printf("short\tunsigned:\t%12d\t%12d\n", 0, USHRT_MAX);
  printf("\t  signed:\t%12d\t%12d\n", SHRT_MIN, SHRT_MAX);
  printf("int\tunsigned:\t%12d\t%12d\n", 0, UINT_MAX);
  printf("\t  signed:\t%12d\t%12d\n", INT_MIN, INT_MAX);
  printf("long\tunsigned:\t%12lu\t%12lu\n", 0lu, ULONG_MAX);
  printf("\t  signed:\t%12ld\t%12ld\n", LONG_MIN, LONG_MAX);
  printf("long long\tunsigned:\t%24llu\t%24llu\n", 0llu, ULONG_LONG_MAX);
//  printf("long long   signed:\t%24lld\t%24lld\n", LONG_LONG_MIN, LONG_LONG_MAX);    // obsolete version of LLONG_MIN, LLONG_MAX
  printf("long long\t  signed:\t%24lld\t%24lld\n", LLONG_MIN, LLONG_MAX);

//  printf("float:\t%f", )
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


/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
  int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


int getline_rewrite(char s[], int lim) {
  int c, i;
  for (i=0; i < lim-1; ++i) {
    if ((c=getchar()) == EOF) { break; }
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


/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}


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


int any(const char s1[], const char s2[]) {
  int i;
  for (i = 0; s1[i] != '\0'; ++i) {
    for (int j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) { return i; }
    }
  }
  return -1;
}


unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
  unsigned mask = (1 << n) - 1;
  return x & (mask << (p + 1 - n)) | ((y & mask) << (p + 1 - n));
}


//Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
//position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
unsigned invert(unsigned x,  unsigned p, unsigned n) {
  
}


//Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
//to the right by n positions


int main() {
//  print_integer_range();

//  print_float_range();

//  printf("%d", htoi_("  0Xff"));

//  char s[] = "helllo? Hello!";
//  squeeze_(s, 'l');
//  printf("%s", s);

//  for (char c = 'a'; c <= 'z'; ++c) {
//    char s2[1];
//    s2[0] = c;
//    printf("%d, ",   any("abcdefghijklmnopqrstuvwxyz", s2));
//  }

//  printf("%u", setbits(0, 8, 8, 255));

  return 0;
}
