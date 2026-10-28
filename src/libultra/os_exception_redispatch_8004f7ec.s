.set noreorder
.set noat
.text

.globl func_8004F7EC
.ent func_8004F7EC
func_8004F7EC:
    nop
    lw      $k1, 0x118($k0)
    lui     $at, 0x2000
    addiu   $t1, $zero, 1
    or      $k1, $k1, $at
    sw      $t1, 0x18($k0)
    /* Re-enter the exception handler at the redispatch label. */
    .word   0x1000FFB5
     sw     $k1, 0x118($k0)
.end func_8004F7EC
