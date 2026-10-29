extern unsigned char D_80138215;
extern unsigned char D_80138216;
extern void func_8003EB80(int, int);
extern float D_80080834;
extern float D_80080838;

void func_8003ED24(int index) {
    if (D_80138215 != 0) {
        D_80138216++;
        func_8003EB80(index, 0);
        if ((float)D_80138216 < D_80080834) {
            func_8003EB80(index, 1);
        }
        if (D_80080838 < (float)D_80138216) {
            D_80138216 = 0;
        }
    }
}
