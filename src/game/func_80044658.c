typedef struct { float x; float y; float z; float sx; float sy; float sz; short s18; } P80073110;
typedef struct { float x; float y; char pad8[0x18]; float f20; } A0_80044658;
typedef struct { char pad[0x23]; unsigned char n; } A2_80044658;
typedef struct { char pad[8]; float f8; char padC[0x18]; float f24; float f28; float f2C; char pad30[0x148-0x30]; } O80044658;
extern P80073110 D_80073110;
typedef struct { char pad[0x8B2C0]; O80044658 objs[1]; } W80044658;
extern W80044658 *D_80126BF0;
extern void func_80006D84(unsigned char, P80073110 *);

void func_80044658(A0_80044658 *arg0, unsigned char arg1, A2_80044658 *arg2, unsigned short arg3, float arg4, float arg5, float arg6) {
    O80044658 *o;
    unsigned char n;
    float t;

    D_80073110.sy = 1.0f;
    D_80073110.s18 = arg3;
    t = D_80073110.sy;
    D_80073110.sz = t;
    D_80073110.sx = t;
    t = arg0->x + arg4;
    D_80073110.x = t;
    arg0->f20 = t;
    D_80073110.y = (arg0->y + arg5) - 1.0f;
    ((unsigned char *)arg0)[arg1 + 0x19] = arg2->n;
    n = arg2->n;
    o = &D_80126BF0->objs[n];
    arg2->n = n + 1;
    func_80006D84(n, &D_80073110);
    o->f2C = 1.0f;
    o->f28 = 1.0f;
    o->f24 = 1.0f;
    o->f8 = arg6;
}
