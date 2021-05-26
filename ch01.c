#include <stdio.h>


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; */
void temperature_table() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--original version--\n");
  printf("Fht\tCelsius\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%4d\t%4d\n", fahr, celsius);
    fahr += step;
  }
}


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * floating-point version
 */
void temperature_table_float() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--floating-point version--\n");
  printf("Fht\tCelsius\n");

  fahr = (float) lower;
  while (fahr <= (float) upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%5.1f\t%7.3f\n", fahr, celsius);
    fahr += (float) step;
  }
}


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * reverse convert version
 */
void temperature_table_reverse_convert() {
  float fahr, celsius;
  int lower, upper, step;

  lower = -20;      // lower limit of temperature table
  upper = 150;    // upper limit
  step = 17;      // step size

  printf("--reverse convert version--\n");
  printf("Celsius\tFht\n");

  celsius = (float) lower;
  while (celsius <= (float) upper) {
    fahr = celsius * 9 / 5 + 32;
    printf("%5.1f\t%7.3f\n", celsius, fahr);
    celsius += (float) step;
  }
}


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * for statement version
 */
void temperature_table_for() {
  int fahr;
  float celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--for statement version--\n");
  printf("Fht\tCelsius\n");

  for (fahr = lower; fahr <= upper; fahr += step) {
    celsius = 5 * ((float) fahr - 32) / 9;
    printf("%5d\t%7.3f\n", fahr, celsius);
  }
}


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * for statement reverse version
 */
void temperature_table_reverse_order() {
  int fahr;
  float celsius;
  int lower, upper, step;

  lower = 0;      // lower limit of temperature table
  upper = 300;    // upper limit
  step = 20;      // step size

  printf("--for statement reverse version--\n");
  printf("Fht\tCelsius\n");

  for (fahr = upper; fahr >= lower; fahr -= step) {
    celsius = 5 * ((float) fahr - 32) / 9;
    printf("%5d\t%7.3f\n", fahr, celsius);
  }
}


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * for statement symbolic constants version
 */
void temperature_table_symbolic_constants() {
  int fahr;
  float celsius;

#define LOWER 0
#define UPPER 300
#define STEP 20

  printf("--for statement symbolic constants version--\n");
  printf("Fht\tCelsius\n");

  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    celsius = 5 * ((float) fahr - 32) / 9;
    printf("%5d\t%7.3f\n", fahr, celsius);
  }
#undef LOWER
#undef UPPER
#undef STEP
}


void test_temperature_table() {
  temperature_table();
  temperature_table_float();
  temperature_table_reverse_convert();
  temperature_table_for();
  temperature_table_reverse_order();
  temperature_table_symbolic_constants();
}


void copy_input_to_output() {
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  printf("[EOF detected]\n");
}

void detab(int tab_width) {
  int c;
  int num_char_this_line = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int num_space = tab_width - (num_char_this_line % tab_width);
      num_char_this_line += num_space;
//      printf(" [%d]", num_space);
      while (num_space--) {
        putchar(' ');
      }
    } else if (c == '\n') {
      putchar(c);
      num_char_this_line = 0;
    } else {
      putchar(c);
      ++num_char_this_line;
    }
  }
}


void emtab(int tab_width) {
  int c;
  int num_char_this_line = 0, num_consecutive_space = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++num_consecutive_space;
    } else {
      if (num_consecutive_space > 0) {
        int num_head = num_char_this_line % tab_width;
        int num_tab = (num_head + num_consecutive_space) / tab_width;
        int num_space = (num_head + num_consecutive_space) - num_tab * tab_width;
        if (num_tab == 0) {
          num_space = num_consecutive_space;
        }
//        printf("[num_tab=%d, num_space=%d]", num_tab, num_space);
        while (num_tab--) {
          putchar('\t');
        }
        while (num_space--) {
          putchar(' ');
        }
        num_char_this_line += num_consecutive_space;
        num_consecutive_space = 0;
      }
      putchar(c);

      if (c == '\n') {
        num_char_this_line = 0;
      } else if (c == '\t') {
        num_char_this_line += tab_width - num_char_this_line % tab_width;
      } else {
        ++num_char_this_line;
      }
    }
  }
}


void fold_long_lines(int width) {
  // TODO
}


void file_io_test() {
  // For Windows: use Ctrl+Z to send EOF with keyboard

//  copy_input_to_output();
//  detab(8);   // 8 for powershell
  emtab(8);   // 8 for powershell

}


int main() {
//  test_temperature_table();
  file_io_test();
  unsigned char i = 0;
  

  return 0;
}
