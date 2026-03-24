//#include <stdint.h>

volatile char * keyboard_write_address_ptr = (char *) (0xFF00);

void put_c(char c) {
    *keyboard_write_address_ptr = c;
}

int main() {
    char x = 0;
    //uint8_t y = 5;
    char c = 'a';

    while (c <= 'z') {
        put_c(c);
        c++;
    }
    return 0;
}