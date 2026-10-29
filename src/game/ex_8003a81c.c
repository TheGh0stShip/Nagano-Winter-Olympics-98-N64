typedef struct Record {
    unsigned char pad0[0x10];
    unsigned char first;
    unsigned char second;
    unsigned char pad12[0x1A];
} Record;

extern Record D_80137DF8[];
extern unsigned char D_80138214;
extern char D_06005DF8[];
extern void *D_80072BB0[];
extern void *D_80072BE0[];
extern int func_8003A638(int);
extern int func_80038FC4(void);
extern void func_800389B4(int);
extern void func_80039004(int index, float x, float y, int first, void *second, int type);
extern void func_800375F0(int index, int flags, float x, float y, float first, float second);

int func_8003A81C(int arg0, int index) {
    unsigned char v;
    int effect;

    arg0 = func_8003A638(arg0);
    if (D_80137DF8[index].second != 0) {
        if (D_80138214 != 4) {
            func_80039004(arg0, -170.0f, 0, 7, D_80072BB0[D_80137DF8[index].second], 1);
            arg0++;
        }
    }
    if (D_80138214 >= 4) {
        v = D_80137DF8[index].first;
        effect = func_80038FC4();
        if (v > 0 && v < 4) {
            func_80039004(arg0, 0.0f, 0.0f, 20, D_80072BE0[v], effect);
            arg0++;
        }
        if (v >= 4 && v < 17) {
            func_80039004(arg0, 0, 0, 20, D_06005DF8, effect);
            arg0++;
            func_800389B4(arg0);
            func_800375F0(arg0, 0x800, -170.0f, 0.0f, 0.0f, v);
            arg0++;
        }
    }
    return arg0;
}
