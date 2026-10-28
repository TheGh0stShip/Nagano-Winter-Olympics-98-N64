.set noreorder
.text

.globl __osRestoreInt
.ent __osRestoreInt
__osRestoreInt:
    mfc0    $t0, $12
    or      $t0, $t0, $a0
    mtc0    $t0, $12
    nop
    nop
    jr      $ra
     nop
.end __osRestoreInt
