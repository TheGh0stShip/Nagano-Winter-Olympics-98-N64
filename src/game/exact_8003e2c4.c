typedef struct Entry {
    unsigned char active;
    unsigned char pad1[8];
    unsigned char b9;
    unsigned char pad_a[2];
    float value;
    unsigned char b10;
    unsigned char pad11;
    unsigned char b12;
    unsigned char pad13[0x2C - 0x13];
} Entry;

extern Entry D_80137DF8[];
extern unsigned char *D_80126BF0;
extern void func_80038B20(Entry *, unsigned char *, int);

void func_8003E2C4(unsigned char *src) {
    unsigned char n = 0;
    unsigned char *q;
    Entry *e;
    int i;
    unsigned char *p;
    unsigned char *r;

    for (e = D_80137DF8, p = src, i = 0, q = src, r = src; i != 40; i += 4) {
        func_80038B20(e, q, 8);
        e->b9 = p[0x5A];
        e->value = *(float *)(r + 0x74);
        e->b10 = p[0x64] + 1;
        switch (D_80126BF0[0x977EC]) {
        case 0:
        case 1:
        case 6:
        case 7:
        case 8:
        case 9:
            if (e->active != 0) {
                e->value = (int)e->value / 10 * 10;
            }
            break;
        case 10:
            break;
        }
        if (i >= 4) {
            if (e->value == e[-1].value) {
                e->b12 = e[-1].b12;
            } else {
                e->b12 = n;
            }
        }
        q += 9;
        e++;
        p++;
        r += 4;
        n++;
    }
}
