extern unsigned char *D_80126BF0;
extern unsigned char D_801374B2;

void func_8002B624(void) {
    D_801374B2 = D_80126BF0[0x977EC];
    if (D_80126BF0[0x977F1] != 20) {
        D_801374B2 = 11;
    }
    if (D_80126BF0[0x977F1] == 7) {
        D_801374B2 = D_80126BF0[0x977EC];
    }
}
