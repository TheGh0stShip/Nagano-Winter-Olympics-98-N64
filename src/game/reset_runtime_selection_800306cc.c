extern unsigned char *D_80126BF0;
extern signed short D_80071F38;
extern unsigned char D_80071F30;
extern unsigned char D_80071F34;

void func_800306CC(void) {
    unsigned char *state = D_80126BF0 + 0x92238;

    *(unsigned int *)(state + 0x12C) = 0;
    *(signed short *)state = 0;
    D_80071F38 = 255;
    D_80071F30 = 0;
    D_80071F34 = 255;
}
