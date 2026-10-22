extern int D_80134010;
extern unsigned char D_80134014;
extern unsigned short D_80134016;
extern int D_80134018;
extern void func_80030EEC(int, float);

void func_8000FAE0(void) {
    D_80134010 = 0;
    D_80134018 = 0;
    D_80134016 = 0;
    func_80030EEC(6, 5.0f);
    D_80134014 = 1;
}
