typedef struct Entry {
    short first;
    unsigned char pad2[0xA];
    float f[6];
    float g[3];
    unsigned char pad30[0xFC];
    int last;
} Entry;

extern unsigned char *D_80126BF0;
extern unsigned char D_801369F0, D_80136A10, D_80136A11, D_80136A12;
extern unsigned char D_80136A13, D_80136A14, D_80136A18, D_80136A24;
extern short D_80136A22;
extern unsigned char D_80136A28[], D_80138274[], D_80138301;
extern unsigned char *D_800731FC[];
extern unsigned char D_80073208[];
extern void func_80003C10(unsigned char *, int);
extern void func_80012788(void);


void func_80043CA8(unsigned char arg) {
    int i, n, j;
    int k1, k2;
    Entry *e;
    func_80003C10(D_80136A28, 4);
    func_80012788();
    for (i = 0x2B90; i < 0x6A58; i += 0x148) {
        e = (Entry *)(D_80126BF0 + i + 0x8B2C0);
        e->first = 0;
        e->f[0] = 0.0f; e->f[1] = 0.0f; e->f[2] = 0.0f;
        e->f[3] = 0.0f; e->f[4] = 0.0f; e->f[5] = 0.0f;
        e->g[0] = 1.0f; e->g[1] = 1.0f; e->g[2] = 1.0f;
        e->last = 0;
    }
    D_80136A24 = 0; D_80136A22 = 0; D_801369F0 = 0;
    k1 = (i & 0) | 0;
    k2 = (i * 0) | 0;
    D_80136A13 = 0; D_80136A14 = 0; D_80136A11 = 0;
    D_80136A10 = arg;
    n = D_80073208[arg];
    i = (int)D_800731FC[arg];
    k1 |= k2; D_80136A12 = k1;
    for (j = 0; j < n; j++) {
        D_80138274[j] = *(unsigned char *)i++;
        if (*(unsigned char *)i == 0xFF) { j++; break; }
    }
    D_80136A18 = 1;
    D_80138301 = 0x12;
}
