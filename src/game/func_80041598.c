typedef struct {
    unsigned char grid[10][9];
    unsigned char lo[10];
    unsigned char hi[10];
    unsigned short w[3];
    float f[10];
} Src;
typedef struct {
    unsigned char grid[10][7];
    unsigned char lo[5];
    unsigned char hi[5];
    unsigned short w[3];
    char pad56[2];
    float f[10];
} Dst;
typedef struct {
    Dst d[12];
    char pad600[0x40];
    unsigned short w[3];
} Save;
extern void func_8000ECBC(int, Src *);

void func_80041598(Save *save) {
    Src src;
    short i;
    short j;
    short k;
    int v;
    Dst *d;

    i = 0;
    while (i < 12) {
        func_8000ECBC(i & 0xFF, &src);
        if (i != 11) {
            d = &save->d[i];
            for (j = 0; j < 10; j++) {
                for (k = 0; k < 7; k++) {
                    if (i) {}
                    if (i) {}
                    if (j) {}
                    d->grid[j][k] = src.grid[j][k] + ((src.grid[j][7] & (1 << k)) << (7 - k));
                }
            }
            for (j = 0; j < 5; j++) d->lo[j] = 0;
            for (j = 0; j < 10; j++) {
                if (j % 2) {
                    v = src.lo[j] << 4;
                } else {
                    v = src.lo[j] & 0xF;
                }
                d->lo[j / 2] |= v;
            }
            for (j = 0; j < 5; j++) d->hi[j] = 0;
            for (j = 0; j < 10; j++) {
                if (j % 2) {
                    v = src.hi[j] << 4;
                } else {
                    v = src.hi[j] & 0xF;
                }
                d->hi[j / 2] |= v;
            }
            for (j = 0; j < 3; j++) d->w[j] = src.w[j];
            for (j = 0; j < 10; j++) d->f[j] = src.f[j];
        } else {
            for (j = 0; j < 3; j++) save->w[j] = src.w[j];
        }
        i++;
    }
}
