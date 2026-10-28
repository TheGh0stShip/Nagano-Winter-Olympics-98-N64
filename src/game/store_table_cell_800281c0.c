extern unsigned char D_801374B2;
extern unsigned char *D_80126BF0;
extern signed char D_80071A5C[];
extern unsigned char D_801371F0[];

void func_800281C0(unsigned char row, unsigned char value) {
    if (D_801374B2 == 11) {
        D_801371F0[row * 7 + D_80071A5C[D_80126BF0[0x977EC]]] = value;
    }
}
