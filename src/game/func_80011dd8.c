typedef struct Gfx {
    unsigned int w0;
    unsigned int w1;
} Gfx;

typedef struct Mtx {
    int m[4][4];
} Mtx;

typedef struct Obj {
    unsigned short active;
    unsigned char pad2[0x12A];
    Gfx *dl;
    unsigned char pad130[8];
} Obj;

typedef struct Pad {
    unsigned short held;
    unsigned char pad2[6];
    unsigned short pressed;
    unsigned char padA[4];
} Pad;

extern unsigned char *D_80126BF0;
extern Gfx *D_80126BF4;
extern Mtx *D_80126BFC;
extern Gfx D_060210A8[];
extern Gfx D_060210B8[];
extern Gfx D_060210C8[];
extern Gfx D_060210D8[];
extern Gfx D_060210E8[];
extern Gfx D_060210F8[];
extern Gfx D_06021118[];
extern Gfx D_06021108[];
extern signed char D_80134DE8;
extern unsigned char D_8006E5E4;
extern unsigned char D_8006E5E8;

extern void func_8005DD18(Mtx *m, float x, float y, float z);
extern void func_8002FD8C(void *, int, int, int);
extern void func_8002FD50(void *, int, int, int, int, int, int);
extern void func_800485AC(int);
extern void func_80004B9C(short);

#define GFX(a, b) { Gfx *_g = D_80126BF4++; _g->w0 = (a); _g->w1 = (b); }
#define MTX(w0) { GFX(w0, (unsigned int)D_80126BFC + 0x80000000); D_80126BFC++; }

void func_80011DD8(void) {
    unsigned short pad0;
    unsigned short a;
    unsigned short b;
    unsigned short i;
    Obj *obj;
    float y;

    a = ((Pad *)(D_80126BF0 + 0x7C8F8))[D_80126BF0[0x977EF]].held;
    b = ((Pad *)(D_80126BF0 + 0x7C8F8))[D_80126BF0[0x977EF]].pressed;
    obj = (Obj *)(D_80126BF0 + 0x8A078);
    obj->dl = D_80126BF4;
    GFX(0x06000000, (unsigned int)D_060210B8);
    func_8005DD18(D_80126BFC, 0.0f, 16.0f, 0.0f);
    MTX(0x01040040);
    GFX(0x06000000, (unsigned int)D_060210A8);
    func_8005DD18(D_80126BFC, 0.0f, 16.0f, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_060210D8);
    func_8005DD18(D_80126BFC, 0.0f, -57.0f, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_060210C8);
    func_8005DD18(D_80126BFC, -58.0f, 8.0f, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_06021118);
    func_8005DD18(D_80126BFC, 0.0f, 17.0f, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_06021118);
    func_8005DD18(D_80126BFC, 0.0f, 16.0f, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_06021118);
    GFX(0xB8000000, 0);
    obj++;
    obj->dl = D_80126BF4;
    if (D_80134DE8 == 0) {
        y = 17.0038166f;
    } else if (D_80134DE8 == 1) {
        y = 0.0f;
    } else if (D_80134DE8 == 2) {
        y = -16.0035915f;
    } else {
        y = -37.0f;
    }
    func_8005DD18(D_80126BFC, -58.0f, y, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_06021108);
    GFX(0xB8000000, 0);
    obj++;
    obj->dl = D_80126BF4;
    func_8005DD18(D_80126BFC, -24.0f, -30.0f, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_060210F8);
    GFX(0xBD000000, 0);
    GFX(0xB8000000, 0);
    if (D_8006E5E4 != 0) {
        func_8002FD8C(obj, 0xCF, 0xCF, 0xCF);
        func_8002FD50(obj, 0xCF, 0xCF, 0xCF, 0, 0, 0x40);
    } else {
        func_8002FD8C(obj, 0x4F, 0x4F, 0x4F);
        func_8002FD50(obj, 0x4F, 0x4F, 0x4F, 0, 0, 0x40);
    }
    obj++;
    obj->dl = D_80126BF4;
    func_8005DD18(D_80126BFC, 32.0f, -30.0f, 0.0f);
    MTX(0x01000040);
    GFX(0x06000000, (unsigned int)D_060210E8);
    GFX(0xB8000000, 0);
    if (D_8006E5E4 != 0) {
        func_8002FD8C(obj, 0x4F, 0x4F, 0x4F);
        func_8002FD50(obj, 0x4F, 0x4F, 0x4F, 0, 0, 0x40);
    } else {
        func_8002FD8C(obj, 0xCF, 0xCF, 0xCF);
        func_8002FD50(obj, 0xCF, 0xCF, 0xCF, 0, 0, 0x40);
    }
    if ((a & 0x400) || (b & 0x400)) {
        D_80134DE8++;
        if (D_80134DE8 >= 3) {
            D_80134DE8 = 2;
        }
    }
    if (((a & 0x800) || (b & 0x800)) && D_80134DE8 > 0) {
        D_80134DE8--;
    }
    if (D_80134DE8 == 2) {
        if ((a & 0x100) || (b & 0x100)) {
            if (D_8006E5E4 != 0) {
                D_8006E5E4 = 0;
            }
            func_800485AC(6);
        }
        if ((a & 0x200) || (b & 0x200)) {
            if (D_8006E5E4 == 0) {
                D_8006E5E4 = 1;
            }
            func_800485AC(5);
        }
    }
    if (D_80134DE8 == 3 && (a & 0x8000)) {
        D_8006E5E8 ^= 1;
    }
    obj = (Obj *)(D_80126BF0 + 0x8A078);
    for (i = 0; i < 5; i++) {
        obj++;
        obj[-1].active = 1;
    }
    if (D_8006E5E8 != 0) {
        D_80134DE8 = 3;
        obj = (Obj *)(D_80126BF0 + 0x8A078);
        for (i = 0; i < 5; i++) {
            obj++;
            obj[-1].active = 0;
        }
        func_80004B9C(0);
    }
}
