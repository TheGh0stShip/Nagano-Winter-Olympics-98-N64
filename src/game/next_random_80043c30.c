extern unsigned int D_80138230;

unsigned short func_80043C30(void) {
    D_80138230 = D_80138230 * 0x6C078965 + 1;
    return (D_80138230 >> 16) & 0x7FFF;
}
