# a (hopefully) generic Makefile for our project, if you only want to compile one file
# assumes z88dk is installed properly
SHELL := /bin/bash

export NAME:=echo
export START_ADDR:=0x0000
export DIS:=z88dk-dis
export CC:=zcc
export CC_TARGET:=+z80 -clib=classic

# these -pragmas (alegedly) remove some reserved memory
# add 	-crt0=../crt0.asm  for the custom crt0
export CC_ARGS:=-mz80 -v -m -O0 -create-app \
 	-pragma-define:CRT_INITIALIZE_BSS=0 \
	-pragma-define:CRT_ORG_CODE=$(START_ADDR) \
	-pragma-define:CLIB_EXIT_STACK_SIZE=0 \
	-pragma-define:CLIB_FOPEN_MAX=3 \
	-pragma-define:REGISTER_SP=0x4000

# any reasonably new python 3 should work. developed with 3.12
export PY:=python
# convert txt dump to a format vivado can use
export VIVADO_SCRIPT:= ../../scripts/make_vivado_file.py

.PHONY: all clean

all: $(NAME).vivado

$(NAME).rom $(NAME).map &: $(NAME).c 
	$(CC) $(CC_TARGET) $(NAME).c $(CC_ARGS) -o $(NAME).out

$(NAME).txt: $(NAME).rom $(NAME).map
	$(DIS) -o $(START_ADDR) -x $(NAME).map $(NAME).rom &> $(NAME).txt;

$(NAME).vivado: $(NAME).txt
	$(PY) $(VIVADO_SCRIPT) $(NAME).txt $(NAME).vivado

clean:
	rm -f *.out *.bin *.map *.rom *.txt *.vivado
