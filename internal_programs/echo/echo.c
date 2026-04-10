#include <stdio.h>
#include "../print_utils.h"

// demo from https://github.com/marinus-lab/z88dk/wiki/Classic--Homebrew

int main() {
    printf("Hello from z88dk!\n");

    while ( 1 ) {
       int c = getchar();
       printf("%c %d\n", c,c);
    }
}