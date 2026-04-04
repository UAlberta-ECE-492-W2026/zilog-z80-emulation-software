// Behold: the world's least optimized prime number finder.

#include <stdio.h>

volatile char * keyboard_write_address_ptr = (char *) (0xFFF0);

int fputc_cons_native(char c) {
   *keyboard_write_address_ptr = c;
}

int is_prime(int p) {
   for (int i = 0; i < p; i++) {
      if (p % i == 0) {
         return 0;
      }
   }
   return 1;
}
int main() {

   int primes_to_find = 256;
   int p = 1;
   while (primes_to_find) {
      printf("Check if %d is prime\n", p);
      if (is_prime(p)) {
         printf("%d is prime!\n", p);
         primes_to_find--;
      }
      p++;
   }
}