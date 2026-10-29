typedef struct Game {
    unsigned char pad0[0x977EC];
    unsigned char mode;
} Game;

extern Game *D_80126BF0;
extern unsigned char D_801374B2;
extern float D_8006E4D0[];
extern unsigned int D_80071B68[];
extern float func_8002AF6C(unsigned short, unsigned char);
extern float func_8002B014(unsigned short, unsigned char);
extern unsigned int func_80046280(unsigned char, float);

float func_800289B4(unsigned short id) {
    float pad;
    float t;
    unsigned int digits;
    unsigned int i;
    unsigned int v;

    t = func_8002AF6C(id, D_80126BF0->mode);
    t += func_8002B014(id, D_80126BF0->mode);
    t += D_8006E4D0[D_80126BF0->mode];
    if (D_801374B2 == 11) {
        t = func_80046280(D_80126BF0->mode, t);
        t += D_8006E4D0[D_801374B2];
    }
    if (D_80071B68[D_801374B2] != 0) {
        for (i = 1; i < D_80071B68[D_801374B2]; i++) {
            t *= 10;
        }
        t = (unsigned int)t;
        for (i = 1; i < D_80071B68[D_801374B2]; i++) {
            t = t * 0.1;
        }
    }
    if (D_80126BF0->mode != 2) {
        return t;
    }
    v = t * 10.0f;
    t = v - v % 5;
    t = t * 0.1;
    return t;
}
