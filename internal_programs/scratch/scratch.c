#include <stdio.h>
/* #pragma printf "" */

volatile char *keyboard_write_address_ptr = (char *)(0xFFF0);

int fputc_cons_native(char c) { *keyboard_write_address_ptr = c; }

int main() {
  printf("Hello, World!\n");
  printf(
      "trying to put in a number: %d, there is some text after the expansion",
      7);
  return 0;
}
