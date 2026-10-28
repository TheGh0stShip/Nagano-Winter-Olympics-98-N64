typedef struct Block {
    short flag;
    short pad2;
    int words[29];
} Block;

extern unsigned char *D_80126BF0;
extern Block D_80068FF0;

void func_8002EC10(void) {
    Block *block = (Block *)(D_80126BF0 + 0x7FB28);

    *(Block *)(D_80126BF0 + 0x7FB28) = D_80068FF0;
    block->flag = 1;
}
