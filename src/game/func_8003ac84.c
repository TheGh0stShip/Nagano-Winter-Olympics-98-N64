typedef struct Entry {
    unsigned char on;
    unsigned char pad1[0xF];
    unsigned char kind;
    unsigned char show;
    unsigned char pad12[0x1A];
} Entry;

extern Entry D_80137DF8[];
extern float D_80138208;
extern unsigned char D_80138214;
extern int func_8003A9C4(int, int, float, float, int);
extern int func_8003EC10(int, float, float, unsigned short);
extern void func_800375F0(int, int, float, float, float, float);
extern void func_8003EB80(int, unsigned short);

int func_8003AC84(int a, int idx, float x, float y, int arg4) {
    int n;
    float py;
    int flag = 1;
    unsigned char c;
    float add;
    int idx2;

    x = (float)(int)x + D_80138208;
    y = (float)(int)y;
    n = func_8003A9C4(a, idx, x, y, arg4);
    idx2 = idx;
    py = (float)(idx * -18) + (60.0f + y);
    idx = n;
    if (D_80137DF8[idx2].show != 0 && D_80138214 != 4) {
        idx = func_8003EC10(n, x + 144.0f, py, 1);
        n++;
    }
    if (D_80138214 >= 4) {
        c = D_80137DF8[idx2].kind;
        if (c > 0 && c < 4) {
            add = 0.0f;
            if (c == 2) {
                add = 3.0f;
            }
            if (c == 3) {
                add = 7.0f;
            }
            func_8003EC10(n, x + 224.0f + add, py, 1);
            n++;
        }
        if (c >= 4 && c < 17) {
            if (D_80137DF8[idx2].on == 0) {
                flag = 0;
            }
            func_8003EC10(n, x + 224.0f, py, flag);
            n++;
            func_800375F0(n, 0x800, 256.0f + x + 8.0f, py, 0.0f, c);
            func_8003EB80(n, flag);
            n++;
        }
    }
    return n;
}
