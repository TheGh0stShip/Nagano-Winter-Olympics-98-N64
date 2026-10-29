extern void func_80039F94(int, int, float);
extern void func_8003A5C8(int, int, int);
extern char D_801380B8;
extern float D_801381FC;
extern unsigned char D_8013820C;
extern signed char D_8013821A;
extern signed char D_8013821B;
extern float D_80080788;

void func_8003CD94(int a) {
    D_801380B8 = 4;
    D_801381FC = D_80080788;
    if (D_8013821B >= 0) {
        func_80039F94(0, 1, 1.5707964f);
        func_80039F94(a - 1, 1, 0.0f);
        D_8013821A++;
    } else {
        func_80039F94(0, 1, 0.0f);
        func_80039F94(a - 1, 1, 1.5707964f);
        D_8013821A--;
    }
    func_8003A5C8(D_8013820C, D_8013821A, a);
}
