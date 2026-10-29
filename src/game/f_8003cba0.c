extern void func_8003BFC8(int mode, unsigned short *first, unsigned short *second);
extern unsigned char D_80138217;
extern unsigned char D_801380B8;
extern float D_801381F8;
extern float D_801381FC;
extern signed char D_8013821A;
extern signed char D_8013821B;
extern float D_8008075C;
extern float D_80080760;

unsigned int func_8003CBA0(int limit, int mode) {
    unsigned short hi;
    unsigned short lo;
    int pad[2];

    func_8003BFC8(mode, &hi, &lo);
    if (D_80138217 == 1) {
        D_801381F8 = D_8008075C;
        D_801380B8 = 5;
    }
    D_801381FC = D_80080760;
    if (hi & 0xC00) {
        if (hi & 0x800) {
            if (D_8013821A > 0) {
                D_8013821B = -1;
                D_801380B8 = 2;
            }
        } else {
            if (D_8013821A < limit) {
                D_8013821B = 1;
                D_801380B8 = 2;
            }
        }
    }
    return lo | (hi << 16);
}
