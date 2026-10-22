extern unsigned char *D_80179920;
extern unsigned char *D_80179924;

void func_8004C43C(void) {
    *(unsigned short *)(D_80179924 + 0x2E) = *D_80179920 << 8;
    D_80179920++;
}
