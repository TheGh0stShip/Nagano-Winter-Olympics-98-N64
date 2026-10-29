#ifndef NAGANO_SYS_ASM_H
#define NAGANO_SYS_ASM_H

#define _MIPS_ISA_MIPS1 1
#define _MIPS_ISA_MIPS2 2
#define _MIPS_ISA_MIPS3 3
#define _MIPS_ISA_MIPS4 4
#define _MIPS_SIM_ABI32 1
#define _MIPS_SIM_NABI32 2
#define _MIPS_SIM_ABI64 3

#define LEAF(symbol) \
    .globl symbol; \
    .align 2; \
    .ent symbol, 0; \
symbol:; \
    .frame sp, 0, ra

#define END(symbol) .end symbol
#define EXPORT(symbol) .globl symbol; symbol:

#define NOP \
    .set noreorder; \
    nop; \
    .set reorder

#define MFC0(reg, copreg) \
    .set noreorder; \
    mfc0 reg, copreg; \
    .set reorder

#define MTC0(reg, copreg) \
    .set noreorder; \
    mtc0 reg, copreg; \
    .set reorder

#define CFC1(reg, copreg) \
    .set noreorder; \
    cfc1 reg, copreg; \
    .set reorder

#define CTC1(reg, copreg) \
    .set noreorder; \
    ctc1 reg, copreg; \
    .set reorder

#endif
