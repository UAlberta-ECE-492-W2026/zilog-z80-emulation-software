#!/bin/bash
# minimal compiler args
zcc +z80 -clib=classic hello_world.c -mz80_strict -v -m -create-app 

# stick compiled binary in a text file
z88dk-dis -o 0x0100 -x a.map a.rom > a.txt