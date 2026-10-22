extern unsigned char D_801374D0[];
extern unsigned char D_801374D8[];
extern unsigned char D_801374E0[];
extern unsigned char D_801374E8[];
extern unsigned short D_801374F0[];
extern void func_8002C670(unsigned short, short);

void func_8002C5DC(unsigned short index) {
    unsigned char value;

    D_801374E0[index] = 10;
    D_801374F0[index] = 0;
    D_801374D8[index] = 0;
    value = D_801374D0[index];
    D_801374E8[index] = 0;
    func_8002C670(index, value);
}
