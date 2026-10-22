extern unsigned char *D_80179920;
extern unsigned char *D_80179924;

void func_8004CE70(void) {
    D_80179924[0x5E] = 0;
    *(unsigned char **)(D_80179924 + 0x60) = D_80179920;
    *(short *)(D_80179924 + 0x40) = 0;
    *(short *)(D_80179924 + 0x32) = *(short *)(D_80179924 + 0x40);
}
