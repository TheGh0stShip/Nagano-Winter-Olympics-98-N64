typedef struct {
    unsigned char name[12];
    float score;
    char pad[0x2C - 0x10];
} Entry;
extern int func_80036FC4(void);
extern void func_800375F0(int, int, float, float, float, float);
extern void func_8003889C(float, float, int, int, int);
extern void func_80038A38(Entry *, float, float, int);
extern void func_8003EB80(int, unsigned short);
extern void func_8003EC10(int, float, float, unsigned short);
extern unsigned char D_80072AFC;
extern unsigned char *D_80126BF0;
extern Entry D_80137DF8[];
extern unsigned char D_80138214;

int func_8003A9C4(int id, int idx, float x, float y, int arg4) {
    int hide;
    float col;
    int flag;
    unsigned short s;
    int c;
    float off;
    Entry *e;
    float sc;

    flag = 1;
    e = &D_80137DF8[idx];
    col = 243.0f;
    if (e->name[0] == 0) {
        flag = 0;
    }
    if (D_80138214 >= 4) {
        col = 196.0f;
    }
    func_8003889C(x + 128.0f, (float)(idx * -18) + 61.0f + y, arg4, id, 0);
    id++;
    func_80038A38(e, x + 36.0f, (float)(idx * -18) + 59.0f + y, id);
    id++;
    s = flag;
    c = func_80036FC4() & 0xFFFF;
    hide = 0;
    off = 0.0f;
    sc = e->score;
    if (D_80126BF0[0x977F1] == 0x15 && D_80138214 == 2 && sc == 0.0f) {
        off = 16.0f;
        hide = 1;
    }
    if (sc < 0.0f) {
        hide = 1;
    }
    if (D_80126BF0[0x977EC] == 0xB && D_80072AFC != 0) {
        s = 0;
    }
    if (hide == 0) {
        func_800375F0(id, c, x + col, (float)(idx * -18) + 60.0f + y, (idx & 7) + 8, sc);
        func_8003EB80(id, s);
    } else {
        func_8003EC10(id, x + col - 41.0f + off, (float)(idx * -18) + 60.0f + y, s);
    }
    id++;
    func_8003EC10(id, x + 23.0f, (float)(idx * -18) + 60.0f + y, flag);
    id++;
    func_8003EC10(id, x, (float)(idx * -18) + 60.0f + y, 1);
    return id + 1;
}
