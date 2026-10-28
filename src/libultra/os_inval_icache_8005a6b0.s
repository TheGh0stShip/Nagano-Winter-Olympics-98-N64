.set noreorder
.set noat
.text

.globl osInvalICache
.ent osInvalICache
osInvalICache:
    blez    $a1, 2f
     nop
    addiu   $t3, $zero, 0x4000
    sltu    $at, $a1, $t3
    beqz    $at, 3f
     nop
    or      $t0, $a0, $zero
    addu    $t1, $a0, $a1
    sltu    $at, $t0, $t1
    beqz    $at, 2f
     nop
    andi    $t2, $t0, 0x1F
    addiu   $t1, $t1, -0x20
    subu    $t0, $t0, $t2
1:
    cache   0x10, 0($t0)
    sltu    $at, $t0, $t1
    bnez    $at, 1b
     addiu  $t0, $t0, 0x20
2:
    jr      $ra
     nop
3:
    lui     $t0, 0x8000
    addu    $t1, $t0, $t3
    addiu   $t1, $t1, -0x20
4:
    cache   0x00, 0($t0)
    sltu    $at, $t0, $t1
    bnez    $at, 4b
     addiu  $t0, $t0, 0x20
    jr      $ra
     nop
.end osInvalICache
    .word   0
    .word   0
    .word   0
