typedef struct {
    char pad0[9];
    unsigned char b9;
    char padA[2];
    float fC;
    char pad10;
    unsigned char b11;
    unsigned char b12;
    char pad13;
    short s14[8];
    signed char b24[8];
} Ent;

typedef struct {
    char pad[0x977F1];
    unsigned char mode;
} Big;

extern Big *D_80126BF0;
extern Ent D_80137DF8[];
extern unsigned char D_80138214;
extern void *D_800725B0[];
extern void *D_80072B64[];
extern void *D_80072BC4[];
extern void *D_80072BE4[];
extern char D_06005DB8[];
extern char D_06005DF8[];
extern char D_06005DA8[];
extern char D_06002370[];
extern int func_80038FC4(void);
extern int func_800389B4(int);
extern void func_80039004(int, float, float, int, void *, unsigned short);
extern void func_800375F0(int, int, float, float, float, float);
extern int func_8003B694(int, int);

int func_8003D218(int idx) {
    int id;
    int i;
    int f;
    union {
        int pad;
        int v;
    } pv;

    id = 0x19;
    f = func_80038FC4();
    for (i = 0; i < 9; i++) {
        pv.pad = func_800389B4(id);
        id++;
    }
    for (i = 0; i < 8; i++) {
        pv.v = D_80137DF8[idx].s14[i];
        if (i == 7) {
            pv.v = D_80137DF8[idx].fC;
        } else if (pv.v == 0) {
            func_80039004(id, 0.0f, 0.0f, 20, D_06005DB8, f);
            id++;
            continue;
        }
        func_800389B4(id);
        func_800375F0(id, 0x800, -170.0f, i * -18 + 43.0f, 0.0f, pv.v);
        id++;
    }
    for (i = 0; i < 7; i++) {
        int v;

        v = D_80137DF8[idx].b24[i];
        if (v >= 16) {
            func_80039004(id, 0.0f, 0.0f, 20, D_06005DB8, f);
            id++;
        } else {
            func_80039004(id, 0.0f, 0.0f, 20, D_06005DF8, f);
            id++;
            func_800389B4(id);
            func_800375F0(id, 0x800, -170.0f, i * -18 + 42.0f, 0.0f, v);
            id++;
        }
    }
    if (D_80138214 != 7) {
        int v;

        v = D_80137DF8[idx].b24[i];
        if (v < 3) {
            func_80039004(id, 0.0f, 0.0f, 20, D_80072BE4[v], 1);
            id++;
        }
        if (v >= 3 && v < 16) {
            func_80039004(id, 0.0f, 0.0f, 20, D_06005DF8, f);
            id++;
            func_800389B4(id);
            func_800375F0(id, 0x800, -170.0f, i * -18 + 42.0f, 0.0f, v + 1);
            id++;
        }
    }
    func_80039004(id, 0.0f, 0.0f, 20, D_06005DA8, f);
    id++;
    func_80039004(id, -170.0f, 0.0f, 7, D_800725B0[D_80137DF8[idx].b9], 1);
    id++;
    func_80039004(id, -170.0f, 0.0f, 7, D_80072B64[D_80137DF8[idx].b12], 1);
    id++;
    func_800389B4(id);
    id++;
    func_80039004(id, -170.0f, 0.0f, 7, D_06002370, 1);
    id++;
    if (D_80138214 == 7) {
        func_80039004(id, -170.0f, 0.0f, 7, D_80072BC4[D_80137DF8[idx].b11], 1);
        id++;
    }
    if (D_80126BF0->mode == 0x15) {
        id = func_8003B694(id, 1);
    }
    return id;
}
