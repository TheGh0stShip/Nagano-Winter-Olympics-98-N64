typedef struct St {
    unsigned char pad0[6];
    unsigned char b06;
    unsigned char pad1[0x11];
    unsigned short h18;
    unsigned short h1A;
    unsigned char pad2;
    unsigned char b1D;
    unsigned char pad3[3];
    unsigned char b21;
    unsigned char pad4[0x25];
    unsigned char b47;
    unsigned char pad5[0x13];
    unsigned char b5B;
    unsigned char pad6[0x36];
    unsigned char b92;
    unsigned char pad7[0x23];
    unsigned char b_B6;
    unsigned char b_B7;
    short hB8[3];
    short hBE[3];
    short hC4[3];
    unsigned char bCA[3];
} St;

extern St *D_80179924;
extern unsigned char D_8017966C;
extern void func_8004D7F4(void);
extern void func_8004A250(int);
extern void func_8004ABDC(void);
extern void func_8004CA84(void);
extern void func_8004AFD8(void);
extern void func_8004BAB8(void);
extern void func_8004BF08(void);
extern void func_8004C390(void);
extern void func_8004B1C8(void);
extern void func_8004C910(void);

void func_8004A9A4(void) {
    int i;
    short diff;
    int v;

    D_80179924->h1A += D_80179924->h18 >> 8;
    if (D_80179924->h1A >= 0x100) {
        D_80179924->h1A &= 0xFF;
        if (D_80179924->b_B6 != 0) {
            diff = D_80179924->b_B6;
            diff -= D_80179924->b_B7;
            if (diff < 0x10) {
                func_8004D7F4();
                return;
            }
            D_80179924->b_B6 = diff;
            D_80179924->b06 |= 1;
        }
        for (i = 0; i != 3; i++) {
            if (D_80179924->bCA[i] != 0) {
                D_80179924->bCA[i]--;
                if (D_80179924->bCA[i] != 0) {
                    D_80179924->hBE[i] += D_80179924->hC4[i];
                } else {
                    D_80179924->hBE[i] = D_80179924->hB8[i];
                }
                switch (i) {
                case 0:
                    D_80179924->b06 |= 2;
                    break;
                case 1:
                    D_80179924->b06 |= 1;
                    break;
                case 2:
                    func_8004A250(D_8017966C);
                    break;
                }
            }
        }
        D_80179924->b21--;
        if (D_80179924->b21 == 0) {
            func_8004ABDC();
            func_8004CA84();
        } else {
            func_8004AFD8();
        }
        if (D_80179924->b1D != 0) {
            func_8004BAB8();
        }
        if (D_80179924->b47 != 0) {
            func_8004BF08();
        }
        if (D_80179924->b5B != 0) {
            func_8004C390();
        }
    } else {
        func_8004B1C8();
    }
    if (D_80179924->b92 != 0) {
        func_8004C910();
    }
}
