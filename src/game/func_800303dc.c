typedef struct { unsigned char a[4]; unsigned char b[4]; unsigned char pad[8]; } Row;
typedef struct { unsigned char a[4]; unsigned char b[4]; Row r[7]; } Lights;
extern short D_80137560;
extern short D_80137562;
extern short D_80137564;

void func_800303DC(char *flags, Lights *l, short amt) {
    short i, j, v;
    short *pv = &D_80137564;
    short *pj = &D_80137562;

    for (j = 0; j < 3; j++) {
        flags[j] = 1;
        v = l->a[j] - amt;
        if (v < 0) {
            v = 0;
        }
        if (v >= 0x100) {
            v = 0xFF;
            flags[j] = 0;
        }
        l->a[j] = v;
        l->b[j] = v;
    }
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 3; j++) {
            v = l->r[i].a[j] - amt;
            if (v < 0) {
                v = 0;
            }
            if (v >= 0x100) {
                v = 0xFF;
                flags[j] = 0;
            }
            l->r[i].a[j] = v;
            l->r[i].b[j] = v;
        }
        *pv = v;
        *pj = j;
    }
    D_80137560 = i;
}
