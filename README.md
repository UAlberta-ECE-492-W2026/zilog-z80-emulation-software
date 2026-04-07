# zilog-z80-emulation-software
Software components of our z80 project

See [our other repo](https://github.com/UAlberta-ECE-492-W2026/zilog-z80-emulation) for HDL components.

We use [z88dk v2.4](https://github.com/z88dk/z88dk/tree/v2.4/ext) for the compiler toolchain.

## Installation and Setup
Be sure to clone this repo with `git clone --recursive git@github.com:UAlberta-ECE-492-W2026/zilog-z80-emulation-software.git`. If you did a regular git clone you can update the submodules with `git submodule update --init --recursive`.

You can [install z88dk by following the instructions here](https://github.com/z88dk/z88dk?tab=readme-ov-file#installation). Alternatively you can run the following commands to built it. Note that these assume you are running some version of ubuntu/debian or WSL inside Windows.

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
External software is in ./external_programs.

+ Advent: A selection of text based adventure games. Comes with it's own compiler (vbcc). Only a few of the games (Almazar, ARNA0660, ODWY0350, ODWY0440, ODWY0550, ODWY0551) both use c and don't use external data files, allowing for easy use on a bare metal z80. Any sort of file I/O relies on OS calls, so these games would need to be refactored before being compiled.

## Developed Programs
Programs developed for this capstone are in ./internal_programs.

+ hello_world: Test text output and compiler.
+ minimum_program: More or less the smallest possible thing you can compile.
