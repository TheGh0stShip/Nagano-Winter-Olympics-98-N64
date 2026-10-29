typedef struct {
    unsigned char pad[0xA0];
    unsigned char tbl[32][7];
    unsigned char flags[16];
} Stats;
extern void func_8002AEA4(float *, unsigned char);
extern float func_8002AF6C(unsigned short, unsigned char);
extern float func_8002B014(unsigned short, unsigned char);
extern void func_8002B624(void);
extern unsigned int func_80046280(unsigned char, float);
extern signed char D_80071A5C[];
extern unsigned char D_80071B98[];
extern float D_80071BA4[][4];
extern unsigned char *D_80126BF0;
extern Stats D_80137150;
extern unsigned char D_801374B2;
extern float D_801374B4;
extern unsigned char D_801374C8;

void func_8002AB2C(void) {
    float best;
    float f;
    float g;
    float sign;
    float vals[16];
    int k;
    unsigned char bi;
    unsigned char i;
    signed char d;
    unsigned char ad;
    unsigned char t;

    best = 0.0f;
    func_8002B624();
    if (D_801374B2 == 0xB) {
        for (i = 0; i < 16; i++) {
            g = (unsigned int)D_80137150.tbl[i][D_80071A5C[D_80126BF0[0x977EC]]];
            if (best < g) {
                bi = i;
                best = g;
            }
        }
        for (i = 0; i < 16; i++) {
            vals[i] = func_8002AF6C(i, D_80126BF0[0x977EC]);
            vals[i] += func_8002B014(i, D_80126BF0[0x977EC]);
        }
        func_8002AEA4(vals, D_80126BF0[0x977EC]);
        D_801374C8 = 200;
        for (i = 0; i < 60; i++) {
            f = func_80046280(D_80126BF0[0x977EC], vals[0]);
            d = f - best;
            if (d == 0) {
                D_801374B4 = vals[0];
                D_80137150.tbl[bi][D_80071A5C[D_80126BF0[0x977EC]]] = func_80046280(D_80126BF0[0x977EC], D_801374B4);
                for (i = 1; i < 16; i++) {
                    if (D_80137150.flags[i] != 0) {
                        D_80137150.tbl[i][D_80071A5C[D_80126BF0[0x977EC]]] -= (signed char)(f - best);
                    }
                }
                return;
            }
            sign = 1.0f;
            if (f < best) {
                sign = -1.0f;
            }
            ad = (d < 0) ? -d : d;
            t = D_80071B98[D_80126BF0[0x977EC]];
            if (ad >= 7) {
                k = 0;
            } else if (ad >= 5) {
                k = 1;
            } else if (ad >= 2) {
                k = 2;
            } else {
                k = 3;
            }
            vals[0] += D_80071BA4[t][k] * sign;
            D_801374B4 = vals[0];
        }
    }
}
