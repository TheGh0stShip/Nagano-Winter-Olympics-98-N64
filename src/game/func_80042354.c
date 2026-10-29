typedef struct {
    unsigned char flags;
    unsigned char a[0xDC - 1];
    unsigned char b[11][0x80];
    unsigned char c[0x724 - 0x65C];
    unsigned char d[0x7CC - 0x724];
} Entry;

extern Entry *D_800730A8;
extern void func_8000EC50(void *);
extern void func_8000ED68(void *);
extern void func_8000ECBC(unsigned char, void *);
extern void func_8000ED18(void *);
extern int func_8004251C(void *, void *);
extern int func_800426D8(void *, void *);
extern int func_800428F8(unsigned char, void *, void *);
extern int func_8004299C(void *, void *);
extern int func_80042AF0(void *, void *);

short func_80042354(unsigned char idx) {
    short ret;
    short pad;
    short pad2;
    short found;
    unsigned char b0[0x114];
    unsigned char b1[0xC4];
    unsigned char b2[0x9C];
    unsigned char b3[0x100];
    short i;

    ret = 0;
    if (!idx);
    if ((D_800730A8[idx].flags >> 2) & 1) {
        func_8000EC50(b0);
        if (func_8004251C(b0, &D_800730A8[idx].a[0]) == 0) {
            func_8000ED68(b1);
            if (func_800426D8(b1, &D_800730A8[idx].d[0]) == 0) {
                found = 0;
                for (i = 0; i < 12; i++) {
                    func_8000ECBC(i, b2);
                    if (func_800428F8(i, b2, &D_800730A8[idx].b[0][0])) {
                        found = 1;
                        break;
                    }
                    if (i == 11) continue;
                    if (func_8004299C(b2, D_800730A8[idx].b[i])) {
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    func_8000ED18(b3);
                    if (func_80042AF0(b3, &D_800730A8[idx].c[0]) == 0) {
                        ret = 1;
                    }
                }
            }
        }
    }
    return ret;
}
