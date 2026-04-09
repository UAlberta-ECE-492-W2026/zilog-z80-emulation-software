// Behold: the world's least optimized prime number finder.

#include <stdio.h>
#include "../print_utils.h"

int is_prime(int p) {
   if (p == 1) {
      return 0;
   }
   if (p <= 3) {
      return 1;
   }
   for (int i = 2; i < p; i++) {
      if (p % i == 0) {
         return 0;
      }
   }
   return 1;
}

int main() {

   int primes_to_find = 64;
   int p = 1;

   printf("Printing %d primes starting at %d.\n", primes_to_find, p);


   while (primes_to_find > 0) {
      //printf("%u\n", p);
      if (is_prime(p)) {
         printf("%d is prime!\n", p);
         primes_to_find--;
      }
      p++;
   }
   printf("Done!");

   return 0;
}