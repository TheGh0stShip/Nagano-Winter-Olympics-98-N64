extern unsigned char D_8006F7B4[];
extern double D_8007E7B8;
extern unsigned long long func_80054118(double value);
extern unsigned long long func_8004EF88(unsigned long long left, unsigned long long right);
extern unsigned long long func_8004EF4C(unsigned long long left, unsigned long long right);

void func_8001C630(int arg0, float seconds, int arg2, int arg3) {
    double scaled;
    unsigned long long ticks;

    scaled = seconds / D_8007E7B8;
    ticks = func_80054118(scaled);

    D_8006F7B4[8] = func_8004EF4C(func_8004EF88(ticks, 10), 10) + '0';
    D_8006F7B4[7] = func_8004EF4C(func_8004EF88(ticks, 100), 10) + '0';
    D_8006F7B4[6] = func_8004EF4C(func_8004EF88(ticks, 1000), 10) + '0';
    D_8006F7B4[4] = func_8004EF4C(func_8004EF88(ticks, 10000), 10) + '0';
    D_8006F7B4[3] = func_8004EF4C(func_8004EF88(ticks, 100000), 6) + '0';
    D_8006F7B4[1] = func_8004EF4C(func_8004EF88(ticks, 600000), 10) + '0';
    D_8006F7B4[0] = func_8004EF4C(func_8004EF88(ticks, 6000000), 6) + '0';
}
