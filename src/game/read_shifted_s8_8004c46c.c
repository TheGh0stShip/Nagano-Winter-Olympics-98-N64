extern signed char *D_80179920;
extern unsigned char *D_80179924;

void func_8004C46C(void) {
    *(unsigned short *)(D_80179924 + 0x30) = *D_80179920 << 2;
    D_80179920++;
}
