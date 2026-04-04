#include <stdio.h>
#pragma printf ""

volatile char * keyboard_write_address_ptr = (char *) (0xFFF0);

int fputc_cons_native(char c) {
   *keyboard_write_address_ptr = c;
}

int main() {
   printk("Hello, World!\n");
   return 0;
}