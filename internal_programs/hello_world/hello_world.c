#include <stdio.h>
#pragma printf ""

#define ROWS 60
#define COLUMNS 80

// any address from 0xFFF0 to 0xFFFF will show up on the software terminal when using the interactive 
// testbench, but only 0xFFF3 will also display on the SSD when running on the FPGA
volatile char * keyboard_write_address_ptr = (char *) (0xFFF3); 
volatile char * char_ram = (char*) (0xEC00); // 80x60 memory mapped array of characters
int cursor_position[2] = {0,0};

//write a byte to the software terminal (when using the interactive testbanch) or to the display byte (when running on the FPGA)
int write_to_software_terminal(char c) {
   *keyboard_write_address_ptr = c;
}

void shift_text_up() {
   // shift everything down by one. the top line of text is discarded
   for (int r =1; r < ROWS; r++) {
      for (int c=0; c < COLUMNS; c++) {
         char_ram[r - 1 * COLUMNS + c] = char_ram[r * COLUMNS + c];
      }
   }
   // blank the last line
   for (int c=0; c < COLUMNS; c++) {
      char_ram[ROWS - 1 * COLUMNS + c] = 0;
   }
}

void newline() {
   if (cursor_position[0] + 1< ROWS) {
      cursor_position[1] = 0;
      cursor_position[0]++;
   } else {
      shift_text_up();
      cursor_position[1] = 0;
   }
}

//write to the char ram for display on the attached vga monitor (assuming running on the FPGA)
void write_to_char_ram(char c) {
   if (c == '\n') {
      newline();
      return;
   }
   char_ram[cursor_position[1] * COLUMNS + cursor_position[0]] = c;
   if (cursor_position[1] + 1 < COLUMNS) {
      cursor_position[1]++;
   } else {
      newline();
   }
}

int write_to_char_ram_simple(char c) {
   char_ram[cursor_position[0]] = c;
   cursor_position[0]++;
}
int fputc_cons_native(char c) {
   write_to_software_terminal(c);
   write_to_char_ram(c);
}

int main() {
   printk("Hello, World!\n");
   return 0;
}