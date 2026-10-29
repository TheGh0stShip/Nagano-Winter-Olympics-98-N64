typedef struct State {
    unsigned char pad[0x977EC];
    unsigned char mode;
    unsigned char padED;
    unsigned char value;
    unsigned char padEF[2];
    unsigned char check;
} State;

extern State *D_80126BF0;
extern unsigned char D_80138214;
extern unsigned char D_80072AFC;
extern unsigned char D_060057D8[];
extern unsigned char D_06011AE0[];
extern unsigned char D_06012480[];
extern unsigned char D_060087F8[];
extern unsigned char D_06008098[];
extern void *D_80073054[];
extern void *D_80073024[];
extern void *D_800724A0[];
extern void *D_80072348[];
extern void *D_80072BF4[];

extern int func_80039544(unsigned char course);
extern void func_800389B4(int id);
extern int func_80038FC4(void);
extern void func_80039004(int id, float x, float y, int size, void *data, int kind);

int func_8003B694(int id, int flag) {
    int size;
    void **left;
    void **right;
    int sel;
    int slot;

    if (flag == 1) {
        func_800389B4(id);
        id++;
        func_800389B4(id);
        id++;
        func_80039004(id++, 0.0f, -93.0f, 16, D_060057D8, 3);
        func_80039004(id++, -50.0f, -93.0f, 7, D_06011AE0, 1);
        func_80039004(id++, 86.0f, -93.0f, 7, D_06012480, 1);
    }
    func_800389B4(id);
    id++;
    size = func_80039544(D_80126BF0->mode);
    left = D_80073054;
    right = D_80073024;
    sel = D_80126BF0->mode;
    if (D_80138214 == 4) {
        size = 10;
        left = D_800724A0;
        right = D_80072348;
        if (D_80126BF0->mode == 0xB) {
            sel = 0xC;
        }
    }
    if (D_80126BF0->check == 0x15 && D_80138214 != 1) {
        func_80039004(id++, -92.0f, 90.0f, 20, D_060087F8, 1);
    } else {
        func_80039004(id++, -92.0f, 90.0f, size, left[sel], 1);
    }
    if (D_80126BF0->check == 0x15 && D_80138214 != 1) {
        func_80039004(id++, -112.0f, 90.0f, 20, D_06008098, func_80038FC4());
    } else {
        func_80039004(id++, -112.0f, 90.0f, size, right[sel], 1);
    }
    if (D_80126BF0->check == 0x15 && D_80072AFC == 0) {
        slot = D_80126BF0->value;
        if (slot >= 7 || slot < 0) {
            slot = 6;
        }
        func_80039004(id++, -112.0f, 90.0f, 7, D_80072BF4[slot], 1);
    }
    return id;
}
