typedef struct Src {
    float x;
    float y;
    unsigned char pad8[0x18];
    int active;
    unsigned char pad24[0xC];
} Src;

typedef struct Ent {
    unsigned short active;
    short pad2;
    unsigned char pad4[8];
    float x;
    float y;
    unsigned char pad14[0x134];
} Ent;

extern unsigned char *D_80126BF0;
extern Src *D_8006C240[];
extern char D_80137DF5;
extern float D_801381F8;
extern float D_80072AE8;
extern float func_80039ACC(float a);
extern void func_80039128(unsigned char a);
extern int func_80036ED0(int a);

int func_8003A378(void) {
    Src *src = D_8006C240[D_80126BF0[0x977EC]];
    Ent *e;
    Src *s;
    float y;
    float x;
    int n;
    int i;

    if (src == 0) {
        return 0;
    }
    D_80137DF5 = 1;
    if (0) {}
    if (0) {}
    if (0) {}
    if (0) {}
    for (i = 0; i < 25; i++) {
        e = (Ent *)(D_80126BF0 + 0x8B2C0) + i;
        if (src[i].active == 0) {
            break;
        }
        e->active = 1;
        if (0) {}
        y = src[i].y;
        x = src[i].x;
        if (y >= 58.0f) {
            n = (int)(func_80039ACC(D_801381F8) * 120.0f + y);
            e->y = n + n / D_80072AE8;
        } else if (y <= -58.0f) {
            n = (int)(y - func_80039ACC(D_801381F8) * 120.0f);
            e->y = n + n / D_80072AE8;
        } else {
            e->y = y;
            if (x >= 0.0f) {
                e->x = func_80039ACC(D_801381F8) * 160.0f + x;
            } else {
                e->x = x - func_80039ACC(D_801381F8) * 160.0f;
            }
        }
    }
    func_80039128(D_80126BF0[0x977EC]);
    return func_80036ED0(0);
}
