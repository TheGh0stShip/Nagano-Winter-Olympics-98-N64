typedef struct InitBlock {
    int words[30];
} InitBlock;

extern InitBlock D_80068FF0;
extern InitBlock D_80069158;
extern unsigned char *D_80126BF0;

void func_80004A04(void) {
    short i;

    for (i = 0; i < 16; i++) {
        *(InitBlock *)(D_80126BF0 + i * 0x78 + 0x7FB28) = D_80068FF0;
    }
    *(unsigned short *)(D_80126BF0 + 0x7FB28) = 1;
    *(InitBlock *)(D_80126BF0 + 0x80230) = D_80069158;
    *(unsigned short *)(D_80126BF0 + 0x80230) = 1;
}
