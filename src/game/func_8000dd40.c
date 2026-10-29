typedef struct Gfx { unsigned int w0; unsigned int w1; } Gfx;
typedef struct GfxI { unsigned int w0; int w1; } GfxI;

typedef struct Obj {
    unsigned short type;
    unsigned short visible;
    char pad4[8];
    float x;
    float y;
    float z;
    char pad18[0x38 - 0x18];
    char sub38[0x12C - 0x38];
    void *tex;
    char pad130[8];
} Obj;

typedef struct Ent {
    int a;
    int b;
    int c;
    int d;
} Ent;

#define TRUE1 1
typedef struct GS {
    char pad0[0x977EC];
    unsigned char mode;
    char pad977ED[0x977F4 - 0x977ED];
    unsigned char flag4;
    char pad977F5[3];
    unsigned char flag8;
} GS;
typedef struct GSS {
    char pad0[0x977F8];
    signed char flag8;
} GSS;
#define BASE ((char *)D_80126BF0)
#define OBJS ((Obj *)(BASE + 0x83EF8))
#define OBJ2 ((Obj *)(BASE + 0x91D18))
#define FLAG8 (((GS *)D_80126BF0)->flag8)
#define FLAG4 (((GS *)D_80126BF0)->flag4)
#define MODE (((GS *)D_80126BF0)->mode)

extern void func_800015C4(int, int, int);
extern int func_80007170(int);
extern void func_80007E5C(void);
extern void func_8000A834(int, int, float, float, float);
extern void func_8000AAC0(void);
extern void func_8000B924(void);
extern int func_8000DA60(void);
extern void func_8000DAC0(void);
extern void func_8000DB7C(void);
extern void func_8000DCC0(void);
extern void func_800118D0(void);
extern void func_8002FB28(void *, int, int, int, int, int, int);
extern void func_8002FC74(void *, int, int, int);
extern void func_80030E54(void);
extern int func_80030F70(void);
extern void func_80035854(void);
extern void func_80036288(int);
extern void func_80036334(void);
extern void func_800485AC(int);
extern void func_801954A0(void);
extern void func_8019A090(void);
extern void func_8019A104(void);
extern void func_8019A230(void);
extern Ent D_80063558[];
extern unsigned char D_8006C3D0;
extern unsigned char D_8006D3B0[];
extern char D_8006D3B8[];
extern short D_8006D438;
extern short D_8006D428[];
extern short D_8006D434[];
extern short D_8006D430[];
extern short D_8006D42C[];
extern char D_0600D168[];
extern unsigned char D_8008F3C8;
extern void *D_80126BF0;
extern Gfx *D_80126BF4;
extern short D_801335C8;
extern unsigned short D_801335CA;
extern signed char D_801335D8;
extern unsigned char D_801335D9;

int func_8000DD40(void) {
    Gfx *g;
    Ent *e;
    Obj *obj;
    unsigned char i;
    short a;
    unsigned int e7;
    Obj *o2;
    Gfx *g1;
    Gfx *g2;
    Gfx *g3;
    Gfx *g4;
    Gfx *g5;
    Gfx *g6;
    Gfx *g7;
    Gfx *g8;
    Gfx *g9;
    Gfx *g10;
    Gfx *g11;
    Gfx *g12;
    Gfx *g13;
    Gfx *g14;
    Gfx *g15;
    unsigned char v;

    if (func_8000DA60() != 0) {
        func_8000DB7C();
    }
    switch (D_801335CA) {
    case 0:
        if (func_80007170(0x1C) == 0) {
            return 0;
        }
        func_8000DCC0();
        obj = OBJS;
        obj->visible = 1;
        obj->x = 360.5f;
        *(short *)(BASE + 0x7F898) = 0;
        for (i = 1; i < 15; i++) {
            OBJS[i].type = 0;
            OBJS[i].visible = 1;
        }
        func_8002FB28(obj->sub38, 0, a = (a & 0) | 0, 0, 0, 0x40, 0x40);
        func_8002FC74(obj->sub38, 0, 0, 0);
        D_801335D8 = 3;
        D_801335CA = 0;
        D_801335C8 = 0x60;
        func_8000A834(0x50, 0, 200.0f, 0.1f, -1.0f);
        D_801335CA = 1;
        break;
    case 1:
        func_8000AAC0();
        D_801335C8--;
        if (D_801335C8 == 0) {
            D_801335C8 = 0x108;
            D_801335CA = 2;
            func_800485AC(0x20);
        }
        break;
    case 2:
        func_8000AAC0();
        D_801335C8--;
        if (D_801335C8 <= 0) {
            obj = (Obj *)((int)D_80126BF0 + 0x83EF8);
            obj->x = 0.5f;
            D_801335CA = 3;
        }
        break;
    case 3:
        func_8000AAC0();
        a = D_8006D438;
        D_801335C8++;
        a += D_801335D8;
        if (a > 0xE0) {
            a = (a & 0) | 0xE0;
            v = 0xE0;
            D_8006D434[2] = a;
        } else if (a < 0) {
            v = 0;
            D_8006D430[4] = 0;
        } else {
            v = a;
            D_8006D42C[6] = a;
        }
        obj = OBJS;
        obj->tex = D_80126BF4;
        func_8002FB28(obj->sub38, v, v, v, 0, 0x40, 0x40);
        func_8002FC74(obj->sub38, v, v, v);
        a = D_8006D438;
        g = D_80126BF4++;
        g->w0 = 0x06000000; g->w1 = (unsigned int)D_0600D168;
        g = D_80126BF4++;
        g->w1 = 0;
        g->w0 = 0xB8000000;
        if (a >= 0xE0 && D_801335D8 > 0) {
            D_801335D8 = 0;
        }
        if (a >= 0xE0) {
            D_801335D8 = -3;
        }
        D_8006D428[8] = a;
        if (a > 0) {
            break;
        }
        obj->type = 0;
        obj->tex = 0;
        D_801335CA = 4;
        func_80030E54();
        return 0;
    case 4:
        if (func_80030F70() != 2) {
            func_8000B924();
            D_801335D9 = 0;
            D_801335CA = 5;
        }
        break;
    case 5:
        func_80007E5C();
        func_8000B924();
        FLAG8 = 1;
        FLAG4 = 0;
        MODE = D_8006D3B0[D_801335D9];
        D_8008F3C8 = 1;
        e = &D_80063558[MODE];
        func_800015C4(e->a, e->b, e->c - e->d);
        D_8008F3C8 = 0;
        D_8006C3D0 = 1;
        func_800118D0();
        if (MODE == 1) {
            func_8019A090();
            func_80036334();
        }
        D_801335C8 = 10;
        D_801335CA = 6;
        break;
    case 6:
        D_801335C8--;
        if (D_801335C8 == 0) {
            D_801335CA = 7;
        }
        break;
    case 7:
        func_8000AAC0();
        e7 = (e7 & 0) | 0xE7000000;
        switch (D_801335D9) {
        case 0:
            func_8019A104();
            func_80035854();
            break;
        case 1:
            func_801954A0();
            break;
        case 2:
            func_801954A0();
            break;
        case 3:
            func_801954A0();
            break;
        case 4:
            func_801954A0();
            break;
        default:
            func_8019A230();
            func_80035854();
            break;
        }
        o2 = OBJ2;
        o2->type = 1;
        o2->y = 0.0f;
        o2->x = 0.0f;
        o2->z = 10.0f;
        o2->tex = D_80126BF4;
        { g1 = D_80126BF4++; g1->w0 = e7; g1->w1 = 0; }
        { g2 = D_80126BF4++; g2->w0 = 0xB900031D; g2->w1 = 0x0C084000; }
        { g3 = D_80126BF4++; g3->w0 = e7; g3->w1 = 0; }
        { g4 = D_80126BF4++; g4->w0 = 0xB6000000; g4->w1 = 0xF3205; }
        { g5 = D_80126BF4++; g5->w0 = 0xB7000000; g5->w1 = 0x22204; }
        { g6 = D_80126BF4++; g6->w0 = e7; g6->w1 = 0; }
        { g7 = D_80126BF4++; g7->w0 = 0xB9000002; g7->w1 = 1; }
        { g8 = D_80126BF4++; g8->w0 = 0xF9000000; g8->w1 = 1; }
        { g9 = D_80126BF4++; g9->w0 = 0xFC327E64; g9->w1 = 0xFFFFFDFE; }
        { g10 = D_80126BF4++; g10->w0 = 0xFA000000; g10->w1 = 0xFF; }
        { g11 = D_80126BF4++; g11->w0 = 0x0400207F; g11->w1 = (unsigned int)D_8006D3B8; }
        { g12 = D_80126BF4++; g12->w0 = 0xB1000204; g12->w1 = 0x40206; }
        { g13 = D_80126BF4++; g13->w0 = 0xB1080A0C; g13->w1 = 0xC0A0E; }
        { g14 = D_80126BF4++; g14->w0 = e7; g14->w1 = 0; }
        { g14 = D_80126BF4++; g14->w0 = 0xB8000000; g14->w1 = 0; }
        if (func_8000DA60() != 0) {
            func_8000DAC0();
        }
        if (FLAG8 == 0) {
            if (MODE == 1 || MODE == 5) {
                func_80036288(0);
                func_80036288(1);
                func_8000B924();
            }
            D_801335D9++;
            if (D_801335D9 >= 6) {
                D_801335CA++;
            } else {
                D_801335CA = 5;
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
