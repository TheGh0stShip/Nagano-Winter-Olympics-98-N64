.set noreorder
.set noat
.text

.globl func_8004F1E0
.ent func_8004F1E0
func_8004F1E0:
    lui     $k0, 0x8005
    addiu   $k0, $k0, -0xE10
    jr      $k0
     nop
.end func_8004F1E0
