typedef struct {
    unsigned char flag;
    char pad1[0xB];
    float fC;
    char pad10[4];
    short arr14[8];
    signed char arr24[8];
} Slot;
typedef struct {
    char pad[0xC];
    float fC;
} Obj;

extern Slot D_80137DF8[];
extern float D_80138208;
extern int D_80072AF4;
extern unsigned char D_80138214;
extern char *D_80126BF0;

extern void func_8003889C(float, float, int, int, int);
extern Obj *func_8003EC10(int, float, float, unsigned short);
extern void func_800375F0(int, int, float, float, float, float);
extern void func_8003EB80(int, unsigned short);
extern void func_80038A38(Slot *, float, float, int);
extern int func_8003BAD0(int, int);

int func_8003D6B0(int arg0) {
    int id;
    float base;
    int vis;
    unsigned short uv;
    int y;
    int i;
    int v;
    int sum;
    int t;
    int t2;
    float x2;
    float c40;
    float yy;
    float fx;
    float w;


    id = 0x19;
    base = D_80138208;
    vis = 1;
    if (D_80137DF8[arg0].flag == 0) {
        vis = 0;
    }
    for (y = 0; y >= -0xA1; y -= 18) {
        func_8003889C(base, y + 61.0f, D_80072AF4, id, 0);
        id++;
    }
    uv = vis;
    c40 = 40.0f + base;
    x2 = 104.0f + base;
    sum = 0;
    for (i = 0, y = 0; i < 8; y -= 18, i++) {
        v = D_80137DF8[arg0].arr14[i];
        if (i == 7) {
            v = D_80137DF8[arg0].fC;
        } else {
            sum += v;
            if (v == 0) {
                v = vis;
                if (D_80126BF0[0x977F1] == 0x15 && D_80126BF0[0x977EE] < i) {
                    v = 0;
                }
                func_8003EC10(id, c40, y + 42.0f, v);
                id++;
                continue;
            }
        }
        func_800375F0(id, 0x800, 64.0f + base, y + 42.0f, 0.0f, v);
        func_8003EB80(id, uv);
        if (D_80126BF0[0x977F1] == 0x15 && i != 7 && D_80126BF0[0x977EE] < i) {
            func_8003EB80(id, 0);
        }
        id++;
    }
    w = 8.0f;
    for (i = 0, y = 0; i != 7; y -= 18, i++) {
        t = D_80137DF8[arg0].arr24[i];
        if (t >= 16) {
            func_8003EC10(id, x2, y + 42.0f, (unsigned short)vis);
            id++;
        } else {
            v = vis;
            fx = 136.0f + w + base;
            if (D_80126BF0[0x977F1] == 0x15 && D_80126BF0[0x977EE] < i) {
                v = 0;
            }
            v = (unsigned short)v;
            yy = y + 42.0f;
            func_8003EC10(id, x2, yy, v);
            id++;
            func_800375F0(id, 0x800, fx, yy, 0.0f, ++t);
            func_8003EB80(id, v);
            id++;
        }
    }
    if (D_80138214 != 7) {
        t2 = D_80137DF8[arg0].arr24[i];
        if (t2 < 3) {
            fx = 0.0;
            if (t2 == 1) fx = 3.0f;
            if (t2 == 2) fx = 7.0f;
            func_8003EC10(id, x2 + fx, y + 42.0f, uv);
            id++;
        }
        if (t2 >= 3 && t2 < 16) {
            yy = y + 42.0f;
            fx = 136.0f + w + base;
            func_8003EC10(id, x2, yy, uv);
            id++;
            func_800375F0(id, 0x800, fx, yy, 0.0f, ++t2);
            func_8003EB80(id, uv);
            id++;
        }
    }
    fx = -72.0f + base;
    func_8003EC10(id, fx, -3.0f, 1)->fC = fx / 360.0f + fx;
    id++;
    func_8003EC10(id, 18.0f + base, 60.0f, uv);
    id++;
    func_8003EC10(id, -6.0f + base, 60.0, 1);
    id++;
    func_80038A38(&D_80137DF8[arg0], 34.0f + base, 59.0f, id);
    id++;
    func_8003EC10(id, -80.0f + base, -83.0f, 1);
    id++;
    if (D_80138214 == 7) {
        func_8003EC10(id, 124.0f + base, 61.0f, 1);
        id++;
    }
    if (D_80126BF0[0x977F1] == 0x15) {
        id = func_8003BAD0(id, 1);
    }
    return id;
}
