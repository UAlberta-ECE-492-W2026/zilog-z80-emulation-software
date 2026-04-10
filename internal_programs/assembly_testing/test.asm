PUBLIC _main
_main:

ld (ix+0), $0a
ld (ix+1), $0b
ld (ix+2), $0c
ld (ix+3), $0d
ld de, $07
ld hl, $03
ldd
ldi
ld (ix+7), $00
ld (ix+6), $00
ld bc, $04
lddr
ld (ix+7), $00
ld (ix+6), $00
ld (ix+5), $00
ld (ix+4), $00
ld bc, $04
ld de, $04
ld hl, $00
ldir