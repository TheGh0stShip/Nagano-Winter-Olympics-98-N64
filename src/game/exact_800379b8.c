extern unsigned char D_80137DF5;
extern int func_8003EB14(int);
extern void func_8003EAE0(int, int);
extern void func_800389B4(int);
extern void func_8003889C(float, float, unsigned short, int, unsigned char);
extern void func_8003EAA8(int, int);
extern void func_8003EB80(int, int);
extern void func_8003EBD0(int, float, float);

void func_800379B8(int index, float x, float y, int mode) {
    if (func_8003EB14(index) == 0) {
        func_8003EAE0(index, 2);
    }
    if (func_8003EB14(index) == 2) {
        func_800389B4(index);
        func_8003889C(x, (int)y + (int)y / 4454.0f, 255, index, mode);
        func_8003EAE0(index, 2);
        func_8003EAA8(index, 0x2001);
        func_8003EB80(index, D_80137DF5);
        if (mode == 1) {
            func_8003EBD0(index, 1.0f, 0.8666667f);
        }
    }
}
