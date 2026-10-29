extern unsigned char D_8006F7A8[];
extern unsigned long long D_8007C990;
extern float D_801366A0;
extern double D_8007E7B0;
extern unsigned long long func_80054118(double value);
extern unsigned long long func_8004F088(unsigned long long left, unsigned long long right);
extern unsigned long long func_8004EF88(unsigned long long left, unsigned long long right);
extern unsigned long long func_8004EF4C(unsigned long long left, unsigned long long right);

void func_8001C444(int arg0, int arg1, int arg2) {
    double scaled;
    unsigned long long ticks;

    ticks = D_8007C990;
    func_8004EF88(func_8004F088(ticks, 1000000000), D_8007C990);
    scaled = D_801366A0 / D_8007E7B0;
    ticks = func_80054118(scaled);

    D_8006F7A8[8] = func_8004EF4C(func_8004EF88(ticks, 10), 10) + '0';
    D_8006F7A8[7] = func_8004EF4C(func_8004EF88(ticks, 100), 10) + '0';
    D_8006F7A8[6] = func_8004EF4C(func_8004EF88(ticks, 1000), 10) + '0';
    D_8006F7A8[4] = func_8004EF4C(func_8004EF88(ticks, 10000), 10) + '0';
    D_8006F7A8[3] = func_8004EF4C(func_8004EF88(ticks, 100000), 6) + '0';
    D_8006F7A8[1] = func_8004EF4C(func_8004EF88(ticks, 600000), 10) + '0';
    D_8006F7A8[0] = func_8004EF4C(func_8004EF88(ticks, 6000000), 6) + '0';
}
