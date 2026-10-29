typedef struct Setup {
    unsigned char count;
    char pad1[3];
    float f4;
    short s8;
    short sA;
    unsigned char bC;
} Setup;

typedef struct Rec138 {
    char pad0[0x10];
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    char pad28[0x110];
} Rec138;

typedef struct Slot98 {
    char pad[0x96];
    short h96;
    char pad2[0];
} Slot98;

extern Setup D_80137720;
extern Slot98 D_80137730[];
extern short D_80137860;
extern float D_80137864;
typedef struct World {
    char pad[0x83F00];
    Rec138 recs[1];
} World;

extern World *D_80126BF0;
extern char D_80072A50[];
extern void func_800437A0(unsigned short, char *, int, unsigned short, int);

#define REC(i) ((D_80126BF0->recs + D_80137720.sA)[i])

int func_800351D0(unsigned char count, unsigned char n, float f, short s, short pos) {
    short i;
    float zero;

    if (count >= 3 || pos + count >= 0x60) {
        return 1;
    }
    zero = 0.0f;
    D_80137720.count = count;
    D_80137720.sA = pos;
    if (f < zero) {
        return 2;
    }
    D_80137720.f4 = f;
    if (s >= 0x10) {
        return 3;
    }
    D_80137720.s8 = s;
    if (n <= 0 || n >= 0xB) {
        return 4;
    }
    D_80137860 = n;
    D_80137864 = 10.0f / (unsigned int)n;
    for (i = 0; i < count; i++) {
        func_800437A0(D_80137720.sA + i, D_80072A50, 0, D_80137720.s8, 0);
        REC(i).f10 = REC(i).f14 = REC(i).f18 = zero;
        REC(i).f1C = REC(i).f20 = REC(i).f24 = 0.5f * D_80137720.f4;
    }
    for (i = 0; i < count; i++) {
        D_80137730[i].h96 = 0;
    }
    D_80137720.bC = 1;
    return 0;
}
