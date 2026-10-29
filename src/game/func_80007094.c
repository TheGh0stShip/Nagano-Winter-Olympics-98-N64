extern int D_80131680;
extern int D_80130C30[];
extern unsigned char *D_80126BF0;
extern void func_80006A98(short);
extern void func_80006748(unsigned char, unsigned char);
extern void func_800061E8(unsigned char, unsigned char *);

void func_80007094(unsigned char mode, unsigned char *list) {
    unsigned short i;
    int *p;
    unsigned char *q;

    if (D_80131680 != 0) {
        *(int *)(D_80126BF0 + 0x7C8E8) = D_80131680;
    }
    p = D_80130C30 + 0x41;
    for (i = 0x41; i < 0x244; i++, p++) {
        *p = 0;
    }
    func_80006A98(mode);
    q = list;
    for (i = 0; i < 4 && *q != 0xFF; i++, q++) {
        func_80006748(mode, *q);
    }
    func_800061E8(mode, list);
}
