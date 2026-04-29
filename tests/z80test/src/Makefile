# gmake

NAME = z80test
VERSION = 1.2a
PKG := $(NAME)-$(VERSION)

PROGS := z80full z80flags z80doc z80docflags z80ccf z80memptr z80ccfscr
SRCS  := main idea crctab tests testmacros print

#.DELETE_ON_ERROR: %.out

z80doc.vivado : z80doc.txt
	python ../../../scripts/make_vivado_file.py z80doc.txt z80doc.vivado

z80doc.txt : z80doc.out
	z88dk-dis -x z80doc.sym z80doc.out > z80doc.txt

z80doc.out : z80doc.asm $(addsuffix .asm,$(SRCS))
	./sjasm -s $<


FILES := Makefile loader.bas $(addsuffix .asm,$(PROGS)) $(addsuffix .asm, $(SRCS))

clean:
	rm -rf *.out *.lst *.tap *.txt *.vivado

