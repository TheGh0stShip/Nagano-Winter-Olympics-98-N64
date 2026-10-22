typedef unsigned char u8;
extern int D_80137700;
extern u8 D_80137710;
extern void func_80030EEC(int, float);
void func_80032040(void) {
    D_80137700 = 0;
    func_80030EEC(6, 3.0f);
    D_80137710 = 1;
}
