extern unsigned short D_801374CA;

unsigned short func_80027CC0(unsigned short amount) {
    D_801374CA += amount + 23;
    D_801374CA &= 0x7FFF;
    return D_801374CA;
}
