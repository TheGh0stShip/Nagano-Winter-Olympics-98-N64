extern unsigned char *D_80126BF0;

int func_8002BCDC(unsigned char enabled) {
    if (D_80126BF0[0x977F1] == 21) {
        if (enabled != 0) {
            return 2;
        }
        return 3;
    }
    if (enabled != 0) {
        return 2;
    }
    return D_80126BF0[0x977F2];
}
