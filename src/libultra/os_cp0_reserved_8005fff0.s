.set noreorder
.set noat
.text

.globl func_8005FFF0
.ent func_8005FFF0
func_8005FFF0:
    nop
    jr      $a3
     mtc0   $zero, $7
.end func_8005FFF0

.align 0
.globl func_8005FFFC
.ent func_8005FFFC
func_8005FFFC:
    mfc0    $t0, $4
    andi    $t0, $t0, 0x80
    bnez    $t0, 1f
     nop
    jr      $ra
1:
     mtc0   $zero, $7
.end func_8005FFFC
