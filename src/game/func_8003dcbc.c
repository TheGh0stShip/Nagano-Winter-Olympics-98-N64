typedef struct {
    char pad[0x977F1];
    unsigned char mode;
} Big;
extern Big *D_80126BF0;
extern unsigned char D_801380B8;
extern float D_80138204;
extern float D_80138208;
extern unsigned char D_80138217;
extern unsigned char D_80137D68;
extern signed char D_8013821E;
extern double D_800807E0;
extern float D_800807E8;
extern double D_800807F0;
extern void func_8003BFC8(int, unsigned short *, unsigned short *);
extern float func_80039ACC(float);
extern void func_8003DC9C(void);
extern void func_8003D218(int);
extern void func_8003D6B0(int);

int func_8003DCBC(void) {
    int pad;
    int ret;
    unsigned short held;
    unsigned short press;
    float f;
    int lim;
    int pad2;

    ret = 0;
    func_8003BFC8(4, &press, &held);
    switch (D_801380B8) {
    case 0:
        D_80138204 += D_800807E0;
        f = func_80039ACC(D_80138204);
        D_80138208 = (1.0 - f) * 320.0;
        if (1.0f <= f) {
            D_801380B8 = 1;
        }
        break;
    case 1:
        if (D_80138217 == 1) {
            D_801380B8 = 6;
        }
        if (held & 0x4000) {
            D_801380B8 = 8;
        }
        if (press & 0x300) {
            if (D_800807E8 < ++D_80137D68) {
                held = press;
                D_80137D68 = 13;
            }
        } else {
            D_80137D68 = 0;
        }
        if (held & 0x300) {
            lim = 9;
            if (D_80126BF0->mode == 0x15) {
                lim = 15;
            }
            if (held & 0x100) {
                D_8013821E++;
            }
            if (held & 0x200) {
                D_8013821E--;
            }
            if (D_8013821E < 0) {
                D_8013821E = 0;
                D_801380B8 = 8;
            }
            if (lim < D_8013821E) {
                D_8013821E = lim;
            }
            func_8003DC9C();
            func_8003D218(D_8013821E);
        }
        break;
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        ret = 1;
        break;
    case 6:
    case 7:
        break;
    case 8:
        D_80138204 -= D_800807F0;
        f = func_80039ACC(D_80138204);
        D_80138208 = (1.0 - f) * 320.0;
        if (f <= 0.0f) {
            D_801380B8 = 5;
        }
        break;
    }
    func_8003D6B0(D_8013821E);
    if (ret == 1) {
        func_8003DC9C();
    }
    return ret;
}
