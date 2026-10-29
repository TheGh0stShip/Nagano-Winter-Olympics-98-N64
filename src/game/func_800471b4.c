extern int D_80138490;
extern float D_80080D84;
extern double D_80080D88;
extern double D_80080D90;
extern unsigned long long D_8007C990;
typedef struct { unsigned char pad[10]; unsigned char s[8]; } S6;
extern S6 D_8006F646;
extern unsigned char D_8006F64E;
extern unsigned char D_8006F64F;
extern unsigned char D_8006F650;
extern unsigned long long func_8004F088(long long a, unsigned long long b);
extern unsigned long long func_8004EF88(unsigned long long a, unsigned long long b);
extern void func_8005C810(unsigned long long a);

void func_800471B4(int arg, float time) {
    float scale;
    int pad1[7];
    int n;
    int pad2;
    int d;
    int i;
    int base;

    if (D_80138490 == 0) {
        scale = 1.0f;
    } else {
        scale = D_80080D84;
    }
    n = scale * (time * D_80080D88) * D_80080D90;
    func_8005C810(func_8004EF88(func_8004F088(n * 1000, D_8007C990), 1000000));
    d = n;
    for (i = 0; i < 7; i++) {
        if (i == 4) base = 6; else base = 10;
        D_8006F646.s[0 - i] = d % base + '0';
        d /= base;
    }
}
