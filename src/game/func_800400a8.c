typedef struct {
    int unk0;
    int code;
    short sub;
    unsigned char pad[4];
    unsigned char name[16];
} Req;
extern int func_80013C24(int, Req *, int *);
extern int func_80040900(void);
extern void func_80040A3C(unsigned char, int);
extern int func_80040A80(unsigned char, int);
extern int func_80040EDC(unsigned char);
extern int D_800730A8;
extern unsigned char D_800730AC;
extern int D_80126BF0;
extern unsigned char *D_800730A0[];

short func_800400A8(unsigned char arg0) {
    volatile short ret;
    short i;
    Req req;
    int handle;
    ret = 0;
    D_800730A8 = D_80126BF0 + 0x92C78;
    req.sub = 0x4134;
    req.code = 0x4E48354A;
    for (i = 0; i < 16; i++) { req.name[i] = D_800730A0[D_800730AC][i]; }
    for (i = 0; i < 4; i++) { req.pad[i] = 0; }
    switch (func_80013C24(0, &req, &handle)) {
    case 0:
        for (i = 0; i < 4; i++) {
            if (i != arg0) {
                func_80040A3C(i, handle);
            }
        }
        if (func_80040EDC(arg0) != 0) {
            ret = 3;
        } else if (func_80040A80(arg0, handle) != 0) {
            ret = 3;
        }
        break;
    case 5:
        handle = func_80040900();
        if (handle < 0) {
            ret = -handle;
        } else if (func_80040EDC(arg0) != 0) {
            ret = 3;
        } else if (func_80040A80(arg0, handle) != 0) {
            ret = 3;
        }
        if (0) {
    default:
            ret = 3;
        }
        break;
    }
    return ret;
}
