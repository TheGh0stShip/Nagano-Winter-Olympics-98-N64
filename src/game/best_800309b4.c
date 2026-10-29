typedef struct StateBlock {
    unsigned char pad0[4];
    short f4;
    unsigned char pad6[0x2A];
    unsigned short f30;
    unsigned char pad32[3];
    unsigned char f35;
} StateBlock;

extern unsigned char *D_80126BF0;
extern unsigned char D_801376B6;
int func_800309B4(signed char arg) {
    StateBlock *s = (StateBlock *)(D_80126BF0 + 0x92380);
    s->f4 = arg;
    if (arg == 0) return 1;
    if (D_801376B6 != 0) {
        if (s->f30 == 1) return 0;
        if (s->f30 == 2) return 1;
    } else {
        s->f30 = 1;
        s->f35 = 0xFF;
        return 0;
    }
}
