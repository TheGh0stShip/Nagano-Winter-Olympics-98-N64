.set noreorder
.set noat
.text

.globl entrypoint
.ent entrypoint
entrypoint:
    lui     $t0, 0x8008
    lui     $t1, 0x0011
    addiu   $t0, $t0, 0x1DE0
    ori     $t1, $t1, 0x36C0
1:
    addi    $t1, $t1, -8
    sw      $zero, 0($t0)
    sw      $zero, 4($t0)
    bnez    $t1, 1b
     addi   $t0, $t0, 8
    lui     $t2, 0x8000
    lui     $sp, 0x8008
    addiu   $t2, $t2, 0x0460
    jr      $t2
     addiu  $sp, $sp, 0x3E58
.end entrypoint
