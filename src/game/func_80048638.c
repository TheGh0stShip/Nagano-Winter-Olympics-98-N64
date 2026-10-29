extern unsigned char D_80179669;
extern unsigned char D_801796D2;
extern unsigned int D_801796D8[];
extern unsigned char D_8017975A;

void func_80048638(unsigned short id, unsigned char hi, unsigned char top) {
    int i;
    unsigned int v;
    int h;

    if ((unsigned int)id != 0) {
        D_80179669 = 0xFF;
        if ((unsigned int)hi == 0 || hi >= 0x80) {
            v = id;
        } else {
            h = hi;
            v = (unsigned int)id + (h << 16);
        }
        if (top != 0) {
            v |= top << 24;
        }
        if (D_801796D2 < 8) {
            if (D_801796D2 != 0) {
                for (i = 0; i < D_801796D2; i++) {
                    if (id == (D_801796D8[i] & 0xFFFF)) {
                        D_80179669 = 0;
                        return;
                    }
                }
            }
            D_801796D8[D_801796D2] = v;
            D_801796D2++;
            if (id >= 0x300 && id < 0x468) {
                D_8017975A = 1;
            }
        }
        D_80179669 = 0;
    }
}
