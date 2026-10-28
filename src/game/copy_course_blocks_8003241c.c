typedef struct Block {
    int words[30];
} Block;

extern unsigned char *D_80126BF0;
extern Block D_800691D0;

void func_8003241C(void) {
    *(short *)(D_80126BF0 + 0x7FB28) = 1;
    *(Block *)(D_80126BF0 + 0x7FBA0) = D_800691D0;
    *(Block *)(D_80126BF0 + 0x7FC18) = D_800691D0;
}
