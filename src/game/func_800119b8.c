typedef struct { int src; int dst; int end; int start; } L80063558;
typedef struct { char pad[0x977EC]; unsigned char idx; } G800119B8;
typedef struct { int state; int pad4; int pad8; int src; int dst; int size; } S801340A0;
extern S801340A0 D_801340A0;
extern unsigned char D_8008F3C8;
extern unsigned char D_8006E5B0;
extern G800119B8 *D_80126BF0;
extern L80063558 D_80063558[];
extern void func_80011C18(void);
extern void func_800015C4(int, int, int);
extern void func_8002C8E0(void);
extern void func_8002D508(void);
extern void func_80035854(void);
extern void func_8000AAC0(void);
extern int func_800125D4(void);
extern void func_80011C3C(void);
extern void func_80011CB4(void);

extern int D_801340B0[];
extern int D_801340AC[];
extern int D_801340A8[];
extern int D_801340A4[];
extern int D_8013409C[];
extern int D_80134098[];
extern int D_80134094[];
extern int D_80134090[];
extern int D_8013408C[];
extern int D_80134088[];
extern int D_80134084[];
extern int D_80134080[];
extern int D_8013407C[];
extern int D_80134078[];
extern int D_80134074[];
extern int D_80134070[];
extern int D_8013406C[];
extern int D_80134068[];
extern int D_80134064[];
extern int D_80134060[];
extern int D_8013405C[];

int func_800119B8(void) {
    L80063558 *e;
    int n;
    int src;
    int dst;
    int size;

    switch (D_801340A0.state) {
    case 0:
        func_80011C18();
        D_801340A0.state = 10;
        break;
    case 10:
        e = &D_80063558[D_80126BF0->idx];
        dst = (e->dst + 7) & ~7;
        src = e->src;
        size = e->end - e->start;
        if (size > 0x3800) { D_801340B0[1] = size; n = 0x3800; } else { D_801340AC[2] = size; n = size; }
        D_8008F3C8 = 1;
        D_801340A8[2] = dst;
        D_801340A4[2] = src;
        size = src;
        func_800015C4(size, dst, n);
        D_8008F3C8 = 0;
        D_8013409C[4] = D_80134098[5] + n;
        size = D_80134088[11];
        D_80134094[7] = D_80134090[8] + n;
        D_8006E5B0 = 0;
        D_801340A0.state = 11;
        size = size - n;
        D_8013408C[10] = size;
        break;
    case 11:
        size = D_80134084[12];
        if (size <= 0) {
            D_801340A0.state = 3;
            break;
        }
        if (size > 0x3800) n = 0x3800; else n = size;
        D_8008F3C8 = 1;
        size = D_80134078[13]; dst = D_80134074[15];
        func_800015C4(size, dst, n);
        D_8008F3C8 = 0;
        size = D_8013405C[22];
        D_80134070[15] = D_8013406C[16] + n;
        D_80134068[18] = D_80134064[19] + n;
        size = size - n;
        D_80134060[21] = size;
        break;
    case 3:
        func_8002C8E0();
        func_8002D508();
        func_80035854();
        func_8000AAC0();
        if (func_800125D4()) return 0;
        func_80011C3C();
        return 0;
    case 4:
        func_80011CB4();
        D_801340A0.state = 0;
        return -1;
    default:
        D_801340A0.state = 0;
        break;
    }
    return 0;
}

