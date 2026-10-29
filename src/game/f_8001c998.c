typedef struct Position {
    short pad0;
    short x;
    short y;
} Position;

extern unsigned char *D_8006F618[];
extern unsigned char D_8006F640[][10];
extern double D_8007E7C0;
extern double func_80054284(unsigned long long value);
extern unsigned long long func_80054118(double value);
extern unsigned long long func_8004EF88(unsigned long long left, unsigned long long right);
extern unsigned long long func_8004EF4C(unsigned long long left, unsigned long long right);

void func_8001C998(Position *position, unsigned char index, unsigned long long ticks, int x, int y) {
    double scaled;
    unsigned long long value;
    unsigned char *s;
    unsigned char *d;

    scaled = func_80054284(ticks) / D_8007E7C0;
    value = func_80054118(scaled);
    s = D_8006F618[index];
    s[8] = func_8004EF4C(func_8004EF88(value, 10), 10) + '0';
    s[7] = func_8004EF4C(func_8004EF88(value, 100), 10) + '0';
    s[6] = func_8004EF4C(func_8004EF88(value, 1000), 10) + '0';
    s[4] = func_8004EF4C(func_8004EF88(value, 10000), 10) + '0';
    s[3] = func_8004EF4C(func_8004EF88(value, 100000), 6) + '0';
    s[1] = func_8004EF4C(func_8004EF88(value, 600000), 10) + '0';
    s[0] = func_8004EF4C(func_8004EF88(value, 6000000), 6) + '0';
    d = D_8006F640[index];
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[3];
    d[3] = s[4];
    d[4] = s[6];
    d[5] = s[7];
    d[6] = s[8];
}
