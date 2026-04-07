#include <stdio.h>
#include "print_utils.h"

int main() {
   printk("0Hello, World!\n");
   printk("1Hello, World!\n");
   printk("2Hello, World!\n");
   printk("3Hello, World!\n");
   shift_text_up();
   return 0;
}