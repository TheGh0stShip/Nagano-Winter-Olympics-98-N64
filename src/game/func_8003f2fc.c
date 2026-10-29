extern unsigned char *D_80126BF0;
extern int D_80072718[4][2];
extern unsigned short D_8013822A;
extern short D_8013822C;
extern unsigned short D_8013822E;
extern unsigned short func_80005C48(void);
extern unsigned short func_80005CAC(void);
extern void func_80042FE8(int, unsigned char, unsigned char);
extern void func_80048580(int);
extern double fabs(double);
#pragma intrinsic(fabs)

#define STICK(i) (*(short *)(D_80126BF0 + (i) * 0xE + 0x7C8FA))
#define STICKY(i) (*(short *)(D_80126BF0 + (i) * 0xE + 0x7C8FC))
#define SEL(i) (*(int *)(D_80126BF0 + (i) * 0x138 + 0x853A4))

signed char func_8003F2FC(unsigned char mask) {
    signed char ret;
    unsigned short held;
    unsigned short trig;
    short i;
    short j;
    short sx;
    short sy;
    float f;

    ret = 0;
    sy = 0;
    sx = 0;
    for (i = 0; i < 4;) { sx += STICK(i++) / 32; }
    i = 0;
    do {
        sy += STICKY(i++) / 32;
    } while (i < 4);
    held = func_80005C48();
    trig = func_80005CAC();
    if (mask >= 0x10) {
        D_8013822C = mask & 3;
        return 0;
    }
    i = 0;
    if (mask == 0) {
        for (i = 0; i < 4; i++) {
            func_80042FE8(0x17, i, 0);
        }
        if (held & 0x8000) {
            func_80048580(0x100);
            return 0;
        }
        if (held & 0x4000) {
            func_80048580(0x46B);
            return -1;
        }
        return 0;
    }
    for (i = 0; i < 4; i++) {
        if (i == D_8013822C) {
            SEL(i) = D_80072718[i][D_8013822E / 12 % 2];
            func_80042FE8(0x17, i, D_8013822E / (i % 2 + 7) % 2);
        } else {
            SEL(i) = D_80072718[i][1];
            func_80042FE8(0x17, i, 0);
        }
    }
    if (!(mask & (1 << D_8013822C))) {
        for (i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                D_8013822C = i;
                break;
            }
        }
    }
    if (D_8013822A == 0xFFFF) {
        D_8013822A--;
    }
    D_8013822A <<= 1;
    if (sx != 0 || sy != 0 || (trig & 0x300)) {
        D_8013822A |= 1;
    }
    if (!(D_8013822A & 2)) {
        if (sx < 0 || (trig & 0x200)) {
            if (D_8013822C > 0) {
                for (i = D_8013822C - 1; i >= 0; i--) {
                    if (mask & (1 << i)) {
                        D_8013822C = i;
                        func_80048580(0x46A);
                        break;
                    }
                }
            }
        } else if ((sx > 0 || (trig & 0x100)) && D_8013822C < 3) {
            for (j = D_8013822C + 1; j < 4; j++) {
                if (mask & (1 << j)) {
                    D_8013822C = j;
                    func_80048580(0x46A);
                    break;
                }
            }
        }
    }
    if (held & 0x8000) {
        func_80048580(0x468);
        SEL(D_8013822C) = D_80072718[D_8013822C][0];
        ret = D_8013822C + 1;
    } else if (held & 0x4000) {
        func_80048580(0x46B);
        SEL(D_8013822C) = D_80072718[D_8013822C][0];
        ret = -1;
    }
    f = fabs(7.5f - (float)((D_8013822E + i * 4) % 16)) * 0.5 + -152.0;
    *(float *)(D_80126BF0 + (D_8013822C << 1) * 0x138 + 0x84040) = f;
    *(float *)(D_80126BF0 + (D_8013822C << 1) * 0x138 + 0x83F08) = f;
    D_8013822E++;
    return ret;
}
