.set noreorder
.set noat
.text

.globl osWritebackDCache
.ent osWritebackDCache
osWritebackDCache:
    blez    $a1, 2f
     nop
    addiu   $t3, $zero, 0x2000
    sltu    $at, $a1, $t3
    beqz    $at, 3f
     nop
    or      $t0, $a0, $zero
    addu    $t1, $a0, $a1
    sltu    $at, $t0, $t1
    beqz    $at, 2f
     nop
    andi    $t2, $t0, 0xF
    addiu   $t1, $t1, -0x10
    subu    $t0, $t0, $t2
1:
    cache   0x19, 0($t0)
    sltu    $at, $t0, $t1
    bnez    $at, 1b
     addiu  $t0, $t0, 0x10
2:
    jr      $ra
     nop
3:
    lui     $t0, 0x8000
    addu    $t1, $t0, $t3
    addiu   $t1, $t1, -0x10
4:
    cache   0x01, 0($t0)
    sltu    $at, $t0, $t1
    bnez    $at, 4b
     addiu  $t0, $t0, 0x10
    jr      $ra
     nop
.end osWritebackDCache
