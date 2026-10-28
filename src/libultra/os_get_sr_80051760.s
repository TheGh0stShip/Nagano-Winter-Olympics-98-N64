.set noreorder
.set noat
.text

.globl __osGetSR
.ent __osGetSR
__osGetSR:
    mfc0    $v0, $12
    jr      $ra
     nop
.end __osGetSR
    .word   0
