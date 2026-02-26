; minimal crt0
    MODULE z80_crt0 

    defc    crt0 = 1

    EXTERN    _main           ;main() is always external to crt0 code

    defc    TAR__register_sp = -1
    defc    TAR__clib_exit_stack_size = 0
    defc    TAR__crt_on_exit = 0x10000

    defc    __CPU_CLOCK = 4000000
    INCLUDE "crt/classic/crt_rules.inc"

start:
    call    _main
