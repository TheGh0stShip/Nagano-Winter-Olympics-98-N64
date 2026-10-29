typedef struct {
    char pad0[0x8];
    unsigned char *unk8;
    char padC[0x25 - 0xC];
    unsigned char unk25;
    char pad26[2];
    int unk28;
    char pad2C[0x7C - 0x2C];
    unsigned char unk7C;
    unsigned char unk7D;
    char pad7E[2];
    int unk80;
    char pad84[0x8A - 0x84];
    short unk8A;
    unsigned char unk8C;
} Obj;
extern unsigned char *D_80179920;
extern Obj *D_80179924;
extern void func_8004C9E4(unsigned char **, unsigned char *, Obj **);

void func_8004CA84(void) {
    int v;
    unsigned char *old;

    old = D_80179920;
    if (*D_80179920++ == 0xE4) {
        if (D_80179924->unk8A == 0) {
            D_80179924->unk8C = 0;
            D_80179924->unk7C = *D_80179920;
            D_80179924->unk7D = *++D_80179920;
            v = *++D_80179920; D_80179920++;
            v = (v - D_80179924->unk25) << 8;
            D_80179924->unk80 = D_80179924->unk28 + v;
            func_8004C9E4(&D_80179920, old, &D_80179924);
        } else {
            D_80179920 += 3;
        }
        D_80179924->unk8 = D_80179920;
    }
}
