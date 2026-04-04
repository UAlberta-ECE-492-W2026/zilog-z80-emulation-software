PUBLIC _main
_main:

ld a, $00
ld hl, $fff3 //address of memory_mapped_display_byte, used to blink the LEDs

_loop_start:
ld (hl), a
add a, 1
jp _loop_start