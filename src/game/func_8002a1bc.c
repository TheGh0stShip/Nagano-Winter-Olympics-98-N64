typedef struct Tables {
    unsigned char pad0[0xA0];
    unsigned char base[16][7];
    unsigned char result[16][7];
} Tables;

extern unsigned char *D_80126BF0;
extern unsigned char D_801374B2;
extern signed char D_80071A5C[];
extern Tables D_80137150;
extern signed char func_8002A29C(unsigned char slot, unsigned char value);

void func_8002A1BC(void) {
    unsigned char i;

    if (D_801374B2 == 11) {
        for (i = 0; i < 16; i++) {
            D_80137150.result[i][D_80071A5C[D_80126BF0[0x977EC]]] = func_8002A29C(D_80071A5C[D_80126BF0[0x977EC]], D_80137150.base[i][D_80071A5C[D_80126BF0[0x977EC]]]);
        }
    }
}
