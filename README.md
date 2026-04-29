# zilog-z80-emulation-software
Software components of our z80 project

See [our other repo](https://github.com/UAlberta-ECE-492-W2026/zilog-z80-emulation) for HDL components.

We use [z88dk v2.4](https://github.com/z88dk/z88dk/tree/v2.4/ext) for the compiler toolchain.

## Instalation and Setup
Be sure to clone this repo with `git clone --recursive git@github.com:UAlberta-ECE-492-W2026/zilog-z80-emulation-software.git`. If you did a regular git clone you can update the submodules with `git submodule update --init --recursive`.

You can [install z88dk by following the instructions here](https://github.com/z88dk/z88dk?tab=readme-ov-file#installation). Alternatively you can run the following commands to built it. Note that these assume you are running some version of ubuntu/debian or WSL inside Windows. Note that z88dk is included in this repo as a submodule.

```
cd z88dk
sudo apt install build-essential bison flex libxml2-dev zlib1g-dev m4 ragel re2c dos2unix texinfo texi2html gdb curl perl cpanminus ccache libboost-all-dev libmodern-perl-perl libyaml-perl liblocal-lib-perl libcapture-tiny-perl libpath-tiny-perl libtext-table-perl libdata-hexdump-perl libregexp-common-perl libclone-perl libfile-slurp-perl pkg-config libgmp3-dev
cpanm --local-lib=~/perl5 App::Prove CPU::Z80::Assembler Data::Dump Data::HexDump File::Path List::Uniq Modern::Perl Object::Tiny::RW Regexp::Common Test::Harness Text::Diff Text::Table YAML::Tiny
eval $(perl -I ~/perl5/lib/perl5/ -Mlocal::lib)
export BUILD_SDCC=1
export BUILD_SDCC_HTTP=1
chmod 777 build.sh
export PATH=${PATH}:`pwd`/bin
export ZCCCFG=`pwd`/lib/config
./build.sh
```

## External Programs
External software is in ./external_programs or ./tests. Since modification was done and figuring out git forking is hard these have been copied directly as files instead of as submodules.

+ [Advent](https://github.com/Quuxplusone/Advent): A selection of text based adventure games. Comes with it's own compiler (vbcc). Only a few of the games (Almazar, ARNA0660, ODWY0350, ODWY0440, ODWY0550, ODWY0551) both use c and don't use external data files, allowing for use on a bare metal z80. Any sort of file I/O relies on OS calls, so these games would need to be refactored before being compiled. Of the 6 games mentioned only Almazar fits within ~60KB and can be run on our z80 implementation. z88dk does [support larger programs](https://github.com/z88dk/z88dk/wiki/More-Than-64k) but we do not implement the 'RST p' instruction that is required for that. Some programs have modified Makefiles that allow use of z88dk, but Almazar is the only one which compiles properly.
+ [z80test](https://github.com/raxoft/z80test/tree/master/src): A test suite for z80. Some modification was needed to get it to play nice with z88dk-ticks and our printing setup. This program requires a copy of [sjasm v0.39j](https://github.com/Konamiman/Sjasm/releases/tag/v0.39j) to assemble. A copy is included at ./tests/sjasm for convenience.

## Developed Programs
Programs developed for this capstone are in ./internal_programs.

+ assembly_testing: Template for assembling assembly, used mostly for writing our top level testbench.
+ blinker: Just writes bytes to the IO mapped memory address as fast a possible. Used for testing the FPGA implementation with a slow clock.
+ echo: Mostly just the [z88dk printing demo](https://github.com/z88dk/z88dk/wiki/Classic--Homebrew).
+ hello_world: Test text output and compiler.
+ minimum_program: More or less the smallest possible thing you can compile that does something interesting.
+ prime_printer: prints prime numbers! Very unoptimized, but still makes a decent demo program. It really shows how much faster the FPGA implementation is than using verilator.

## Compiling a Program
Compile the intended program with some soft of z80 compiler. z88dk is recommended, as otherwise you will need to figure out the printing/console interface yourself. The ROM then needs to be reformatted into a text file that is a list of bytes. This is done by ./scripts/make_vivado_file.py. See ./internal_programs/hello_world/Makefile for an example makefile. For details on the compiler arguments used see [this z88dk git wiki page](https://github.com/z88dk/z88dk/wiki/Classic--Pragmas). For instructions on how to run a program either on the FPGA or verilator testbench see the README in the main [hardware git repo](https://github.com/UAlberta-ECE-492-W2026/zilog-z80-emulation).
