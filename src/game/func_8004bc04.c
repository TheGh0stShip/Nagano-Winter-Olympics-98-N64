typedef struct L3 { int pad[2]; int unk8; } L3;
typedef struct L2 { int pad[4]; L3 *unk10; } L2;
typedef struct L1 { int pad[3]; L2 *unkC[1]; } L1;
typedef struct L0 { int pad; L1 *unk4; } L0;

typedef struct Car {
    unsigned char pad0[0xC];
    unsigned char unkC;
    unsigned char unkD;
    unsigned char padE[0x14 - 0xE];
    int unk14;
    unsigned char pad18[0x2C - 0x18];
    short unk2C;
    unsigned char pad2E[0x4E - 0x2E];
    unsigned short unk4E;
    unsigned short unk50;
    short unk52;
    short unk54;
    unsigned short unk56;
    unsigned short unk58;
    unsigned char unk5A;
    unsigned char unk5B;
} Car;

extern Car *D_80179924;
extern L0 *D_8013D658[];
extern unsigned short D_80073A5A[];
extern unsigned char D_8017966C;
extern void func_8004A250(unsigned char);

void func_8004BC04(signed char *p) {
    L1 *a3;
    int b1;
    int b2;
    L2 *it;
    L3 *lf;

    a3 = D_8013D658[D_80179924->unkC]->unk4;
    it = a3->unkC[D_80179924->unkD];
    lf = it->unk10;
    D_80179924->unk14 = lf->unk8;
    D_80179924->unk2C = *p++ << 8;
    D_80179924->unk2C += *p++ * 4;
    D_80179924->unk4E = D_80073A5A[0x42 - *p++];
    b1 = *(unsigned char *)p++;
    D_80179924->unk50 = D_80073A5A[0 - ((b1 & 0xF0) >> 2)];
    D_80179924->unk54 = (b1 & 0xF) * 4;
    b2 = *(unsigned char *)p++;
    if (b2 == 0) {
        D_80179924->unk52 = 0;
    } else {
        if (b2) {}
        D_80179924->unk52 = D_80073A5A[0x42 - b2] + 1;
    }
    if ((int)a3 | (int)it | (int)lf) {}
    D_80179924->unk56 = D_80073A5A[0x40 - *p++ * 4];
    if (D_80179924->unk58 < 0x8000) {
        D_80179924->unk58 = *p << 8;
        D_80179924->unk5B = 0;
    }
    func_8004A250(D_8017966C);
}
