extern unsigned int D_800622E8[];
extern signed char D_8008F3C8;
extern void func_800015C4(unsigned int, unsigned char *, int);
extern int func_8000BB14(int, unsigned char *, int);
extern void func_80051340(unsigned char *, int);

unsigned char *func_800014D8(unsigned int id, unsigned char *dest) {
    unsigned char *r;
    int off;

    r = dest;
    off = D_800622E8[(id - 1) * 2 + 4] & 0x7FFFFFFF;
    if (id != 0) {
        if (!(D_800622E8[(id - 1) * 2 + 4] & 0x80000000)) {
            D_8008F3C8 = 1;
            func_800015C4(D_800622E8[(id - 1) * 2 + 4], dest, D_800622E8[(id - 1) * 2 + 5] - D_800622E8[(id - 1) * 2 + 4]);
            D_8008F3C8 = 0;
            r = dest + (D_800622E8[(id - 1) * 2 + 5] - D_800622E8[(id - 1) * 2 + 4]);
        } else {
            D_8008F3C8 = 1;
            r = (unsigned char *)func_8000BB14(off, dest, (int)(D_800622E8[(id - 1) * 2 + 5] - off));
            func_80051340(dest, D_800622E8[(id - 1) * 2 + 5] - off);
            D_8008F3C8 = 0;
        }
    }
    return r;
}
