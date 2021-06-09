#include <stdio.h>
#include <string.h>

#define abs(x) ((x < 0) ? -x : x)

//int abs(int a) {
//  return (a < 0) ? -a : a;
//}

/* Exercise 3-1. Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside.)
 * Write a version with only one test inside the loop and measure the difference in run-time.
 */
// slower than original version, but no asymptotic difference
int binary_search_(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (v[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return (v[low] == x) ? low : -1;
}


/* original binary_search: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binary_search(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (x < v[mid]) {
      high = mid + 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}


/* Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
 * visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
 * Write a function for the other direction as well, converting escape sequences into the real characters.
 */
void escape(char s[], char t[]) {
  int i = 0, j = 0;
  int c;

  while ((c = s[i]) != '\0') {
    switch (c) {
      case '\n':
        t[j++] = '\\';
        t[j++] = 'n';
        break;
      case '\t':
        t[j++] = '\\';
        t[j++] = 't';
        break;
      case '\\':
        t[j++] = '\\';
        break;
      default:
        t[j++] = c;
    }
  }
  t[j] = '\0';
}


void escape_reverse(char s[], char t[]) {
  int i = 0, j = 0;
  char c;

  while ((c = s[i++]) != '\0') {
    if (c == '\\') {
      if (s[i++] == '\0') {   // impossible, input error
        return;
      } else {
        char c_next = s[i++];
        switch (c_next) {
          case 'n':
            t[j++] = '\n';
            break;
          case 't':
            t[j++] = '\t';
            break;
          case '\\':
            t[j++] = '\\';
            break;
          default:
            t[j++] = c;
            t[j++] = c_next;
            break;
        }
      }
    } else {
      t[j++] = c;
    }
  }
}


/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1
 * into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */
void expand(char s1[], char s2[]) {
  // TODO
}


/* Exercise 3-4. In a two's complement number representation, our version of itoa does not handle
 * the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not.
 * Modify it to print that value correctly, regardless of the machine on which it runs.
 */
// Answer: Largest negative number do not have a positive counterpart in two's complements number representation.
void reverse(char s[]);


void itoa_(int n, char s[]) {
  int i, sign;

  sign = n;

  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) { s[i++] = '-'; }

  s[i] = '\0';
  reverse(s);
}
// NOTE: C99 requires that when a/b is representable: (a/b) * b + a%b shall equal a


/* reverse: reverse string s in place. */
void reverse(char s[]) {
  int i, j;
  char c;

  for (i = 0, j = (int) strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}


/* original itoa: convert n to characters in s */
void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}


/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation
 * in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 */
void itob(int n, char s[], int b) {
  int i, sign;

  sign = n;

  i = 0;
  do {
    s[i++] = abs(n % b) + '0';
  } while ((n /= b) != 0);

  if (sign < 0) { s[i++] = '-'; }

  s[i] = '\0';
  reverse(s);
}


/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary
 * to make it wide enough.
 */
void itoa__(int n, char s[], int width) {
  int i, sign;

  sign = n;

  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);

  while (i < width) { s[i++] = '0'; }

  if (sign < 0) { s[i++] = '-'; }
  s[i] = '\0';
  reverse(s);
}


int main() {
//  char s[16];
//  itoa__(234, s, 7);
//  printf("%s\n", s);
  return 0;
}
