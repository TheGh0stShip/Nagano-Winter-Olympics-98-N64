typedef struct Runtime {
    unsigned char pad0[0x977EC];
    unsigned char mode;
} Runtime;

typedef struct Snd3 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
} Snd3;

extern Runtime *D_80126BF0;
extern unsigned char D_80071B28[];
extern unsigned short D_80071A74[][4];
extern Snd3 D_80071AD4[];

extern void func_8002BC80(unsigned short *, int);
extern int func_8002BCDC(unsigned char);
extern int func_8002BD38(void);
extern int func_8002BD60(float, unsigned char);
extern int func_8002BD84(float);
extern int func_8002BE60(float);
extern int func_8002BEBC(float);
extern int func_8002BF54(float, unsigned char);
extern void func_80048A78(unsigned short);

void func_8002B84C(unsigned char arg0, float arg1) {
    int r;
    unsigned short count;
    unsigned short i;
    unsigned short v;
    unsigned short base;
    unsigned short snd;

    if (arg1 < 0.0f) {
        return;
    }
    count = D_80071B28[D_80126BF0->mode];
    snd = D_80071A74[D_80126BF0->mode][func_8002BCDC(arg0)];
    if (snd != 0xFFFF) {
        func_80048A78(snd);
    }
    snd = D_80071AD4[D_80126BF0->mode].a;
    if (snd != 0xFFFF) {
        if (func_8002BD38() != 0) {
            v = (unsigned short)(r = func_8002BEBC(arg1));
        } else {
            v = (unsigned short)(r = func_8002BE60(arg1));
        }
        if (r != 0) {
            func_8002BC80(&base, 0);
            func_80048A78(base + v);
            func_80048A78(snd);
        }
    }
    snd = D_80071AD4[D_80126BF0->mode].b;
    if (snd != 0xFFFF) {
        if (func_8002BD38() != 0) {
            v = (unsigned short)func_8002BEBC(arg1);
        } else {
            v = (unsigned short)func_8002BD84(arg1);
        }
        func_8002BC80(&base, 0);
        func_80048A78(base + v);
        func_80048A78(snd);
    }
    snd = D_80071AD4[D_80126BF0->mode].c;
    if (snd != 0xFFFF) {
        for (i = 0; i < count; i++) {
            v = i;
            func_8002BC80(&base, (v != (count - 1)) ? 0 : 1);
            if (func_8002BD38() != 0) {
                v = (unsigned short)func_8002BF54(arg1, v + 1);
            } else {
                v = (unsigned short)func_8002BD60(arg1, v + 1);
            }
            func_80048A78(base + v);
        }
        func_80048A78(snd);
    }
}
