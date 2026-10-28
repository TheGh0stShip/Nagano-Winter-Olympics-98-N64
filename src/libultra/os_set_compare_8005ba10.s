.set noreorder
.set noat
.text

.globl __osSetCompare
.ent __osSetCompare
__osSetCompare:
    mtc0    $a0, $11
    jr      $ra
     nop
.end __osSetCompare
    .word   0
