typedef struct Chan {
    unsigned char pad0[6];
    unsigned char unk6;
    unsigned char pad7;
    unsigned char *unk8;
    unsigned char padC[2];
    unsigned char unkE;
    unsigned char unkF;
    unsigned char pad10[4];
    int unk14;
    unsigned char pad18[8];
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char pad26[2];
    int unk28;
    short unk2C;
    short unk2E;
    short unk30;
    short unk32;
    short unk34;
    short unk36;
    unsigned char pad38[0x10];
    char unk48;
    unsigned char pad49[3];
    unsigned short unk4C;
    unsigned char pad4E[0x2F];
    unsigned char unk7D;
    unsigned char pad7E[6];
    int unk84;
    short unk88;
    short unk8A;
    unsigned char pad8C[0xE];
    unsigned short unk9A;
    unsigned char pad9C[0x12];
    unsigned short unkAE;
} Chan;

extern void func_8004B274(void);
extern void func_8004B3E0(void);
extern void func_8004B774(void);
extern void func_8004B94C(void);
extern void func_8004BD70(void);
extern void func_8004C600(void);
extern void func_8004CCD0(void);
extern void func_80051E00(int, void *, int);
extern void func_8005FDD0(int, void *);
extern int D_8007C910;
extern unsigned char D_8017966C;
extern unsigned char D_80179760[];
extern unsigned char *D_80179920;
extern Chan *D_80179924;
extern void (*D_800734B0[])(void);

void func_8004ABDC(void) {
    unsigned char b;
    unsigned char fresh;
    int cmd;

    fresh = 0;
    if (D_80179924->unk22 == 0) {
        fresh = 1;
    } else if (D_80179924->unkE != 0) {
        D_80179924->unkF = 0;
        D_80179924->unkE = 0;
        func_8005FDD0(D_8007C910, D_80179760 + D_8017966C * 0x1C);
    }
    D_80179920 = D_80179924->unk8;
    b = *D_80179920++;
    cmd = b;
    while (cmd >= 0xD0) {
        D_800734B0[cmd]();
        switch (cmd) {
        case 0xF2:
        case 0xF3:
            D_80179924->unk8 = D_80179920;
            return;
        case 0xFF:
            return;
        }
        b = *D_80179920++;
        cmd = b;
    }
    D_80179924->unk84 = D_80179924->unk28;
    if (cmd < 0x68) {
        D_80179924->unk25 = b;
    } else {
        D_80179924->unk25 = cmd - 0x68;
    }
    if (D_80179924->unk25 >= 0x48) {
        if (D_80179924->unk25 == 0x67) {
            D_80179924->unk25 = *D_80179920++;
        }
        D_80179924->unk6 |= 4;
        func_8004BD70();
        D_80179924->unk25 = 0x3C;
    } else {
        D_80179924->unk6 &= 0xFB;
    }
    D_80179924->unk28 = D_80179924->unk25 << 8;
    D_80179924->unk28 += D_80179924->unk2C;
    D_80179924->unk28 += D_80179924->unk2E;
    D_80179924->unk28 += D_80179924->unk30;
    D_80179924->unk28 += D_80179924->unk32;
    D_80179924->unk28 += D_80179924->unk34;
    if (cmd < 0x68) {
        D_80179924->unk20 = *D_80179920++;
    }
    D_80179924->unk21 = D_80179924->unk20;
    b = *D_80179920++;
    cmd = b;
    {
        if (cmd < 0x80) {
            D_80179924->unk23 = cmd;
            b = *D_80179920++;
            cmd = b;
        }
        D_80179924->unk22 = D_80179924->unk23;
        if (D_80179924->unk22 == 0) {
            D_80179924->unk24 = 0;
        } else {
            D_80179924->unk24 = (D_80179924->unk21 * D_80179924->unk22) >> 7;
            if (D_80179924->unk24 == 0) {
                D_80179924->unk24 = 1;
            }
        }
        D_80179924->unk48 = cmd & 0x7F;
    }
    D_80179924->unk8 = D_80179920;
    if (D_80179924->unk8A == 0) {
        D_80179924->unk7D = 0;
    } else {
        func_8004CCD0();
    }
    D_80179924->unk36 = 0;
    if (D_80179924->unk9A != 0) {
        func_8004C600();
    }
    func_8004B274();
    if (fresh == 0) {
        D_80179924->unkAE = 0xFFFF;
        func_8004B774();
        D_80179924->unkE = 1;
        func_80051E00(D_8007C910, D_80179760 + D_8017966C * 0x1C, D_80179924->unk14);
        return;
    }
    D_80179924->unk6 |= 1;
    if (D_80179924->unk4C != 0) {
        func_8004B94C();
    }
    if (D_80179924->unk6 & 1) {
        func_8004B3E0();
    }
}
