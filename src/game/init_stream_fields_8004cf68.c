extern unsigned char *D_80179920;
extern unsigned char *D_80179924;

void func_8004CF68(void) {
    D_80179924[0x64] = 0;
    *(unsigned char **)(D_80179924 + 0x68) = D_80179920;
    *(short *)(D_80179924 + 0x42) = 0;
    *(short *)(D_80179924 + 0x34) = *(short *)(D_80179924 + 0x42);
}
