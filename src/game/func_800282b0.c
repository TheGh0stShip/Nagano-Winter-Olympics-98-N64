typedef struct Runtime {
    unsigned char pad0[0x977EC];
    unsigned char mode;
    unsigned char pad977ED[2];
    unsigned char round;
    unsigned char rounds;
    unsigned char event;
    unsigned char count;
} Runtime;

typedef struct Track {
    unsigned char pad0[0x180];
    unsigned char active[16];
    float level[16];
} Track;

extern Runtime *D_80126BF0;
extern unsigned char D_801374B2;
extern Track D_80137150;
extern signed char D_80071A50[];
extern float D_800800B0;
extern float D_800800B4;

extern void func_800281C0(unsigned char a, unsigned char b);
extern void func_80028264(float a);
extern float func_80028460(unsigned char a);
extern void func_8002AB2C(void);
extern void func_8002B0FC(int a, int b);

void func_800282B0(void) {
    unsigned char i;
    float f;

    if (D_80126BF0->round != 0) return;
    if (D_801374B2 == 0xB && D_80126BF0->mode == 6) return;
    if (D_801374B2 != 0xB && D_80126BF0->count == 0) return;
    for (i = 0; i < 16; i++) {
        if (D_80137150.active[i] == 0) {
            f = func_80028460(i);
            D_80137150.level[i] += f;
            func_800281C0(i, (unsigned int)f);
        }
    }
    if (D_80071A50[D_801374B2] == 1) {
        func_80028264(D_800800B0);
    }
    func_8002B0FC(0, 0xF);
    if (D_80071A50[D_801374B2] == 1) {
        func_80028264(D_800800B4);
    }
    func_8002AB2C();
}
