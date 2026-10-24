extern unsigned char *D_80126BF0;

int func_800349F0(void) {
    if (D_80126BF0[0x977F1] == 20 &&
        D_80126BF0[0x977EC] == 11 &&
        D_80126BF0[0x977F0] == 2) {
        return 1;
    }
    return 0;
}
