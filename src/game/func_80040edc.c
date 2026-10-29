typedef struct Save {
  union {
    unsigned char raw[0x7BE];
    struct {
    unsigned char hdr;
    unsigned char data[0x7BD];
    } s;
  } u;
    unsigned char b7BE;
    unsigned char b7BF;
    unsigned char pad7C0[4];
    unsigned int sum1;
    unsigned int sum2;
} Save;

extern Save *D_800730A8;
extern int *D_800707CC;
extern unsigned char D_8006D450;
extern short func_80042354(unsigned char slot);
extern void func_80041194(unsigned char *p);
extern void func_80041344(unsigned char *p);
extern void func_8004156C(unsigned char *p);
extern void func_80011CD4(unsigned char *p);

int func_80040EDC(unsigned char slot) {
    unsigned int i;
    unsigned int k;
    short found;
    unsigned char *p;
    unsigned int sum;
    int off;
    Save *arr[5];
    unsigned char b;

    for (i = 0; i < 5; i++) { arr[i] = &D_800730A8[i]; }
    for (i = 0; i < sizeof(Save); i++) { D_800730A8[slot].u.raw[i] = 0; }
    found = 0;
    for (i = 0; i < 4; i++) {
        if (i != slot) {
            found = func_80042354(i);
            if (found != 0) break;
        }
    }
    if (found != 0) {
        D_800730A8[slot].u.s.hdr = D_800730A8[i].u.s.hdr;
    } else {
        for (i = 0; i < 4; i++) {
            found = 0;
            for (k = 0; k != 4; k++) {
                if (k != slot) {
                    if (((D_800730A8[k].u.s.hdr >> 2) & 1) == 1 && i == (D_800730A8[k].u.s.hdr & 3)) { found = 1; break; }
                }
            }
            if (found == 0) {
                D_800730A8[slot].u.s.hdr = i | 4;
                break;
            }
        }
    }
    func_80041194(&D_800730A8[slot].u.s.data[0]);
    func_80041344((unsigned char *)&D_800730A8[slot] + 0x724);
    func_8004156C((unsigned char *)&D_800730A8[slot] + 0xDC);
    func_80011CD4(&b);
    D_800730A8[slot].b7BE = b;
    D_800730A8[slot].b7BF = D_8006D450;
    p = (unsigned char *)&D_800730A8[slot];
    sum = 0;
    for (i = 0; i < (unsigned int)((unsigned char *)&D_800730A8[slot].sum1 - (unsigned char *)&D_800730A8[slot]); i++) { sum += p[i]; }
    D_800730A8[slot].sum1 = sum;
    sum = 0;
    for (i = 0; i < (unsigned int)((unsigned char *)&D_800730A8[slot].sum1 - (unsigned char *)&D_800730A8[slot]) >> 1; i++) { sum += p[i * 2]; }
    D_800730A8[slot].sum2 = sum;
    return 0;
}
