extern int func_8003C6B4(int);
extern void func_80006080(char *, int, char *);
extern void func_80039A8C(void);
extern void func_80038E88(int);
extern int func_8003B694(int, int);
extern void func_8003A5C8(int, int, int);
extern void func_8003C780(void);
extern char D_80072AF8;
extern char D_80072AFC;
extern char D_80063990[];
extern char D_80138214;
extern signed char D_8013821A;
extern float D_801381E0;
extern unsigned char *D_80126BF0;

int func_8003CA5C(int a, int b) {
    int v;
    int w;
    int r;
    char buf;

    D_80072AFC = 0;
    D_80072AF8 = 1;
    r = func_8003C6B4(a);
    if (r == a) {
        return a;
    }
    func_80006080(&buf, 20, D_80063990);
    D_80138214 = a;
    func_80039A8C();
    D_8013821A = b;
    D_801381E0 = D_8013821A * 18;
    func_80038E88(D_80126BF0[0x977EC]);
    v = func_8003B694(25, 0);
    func_8003A5C8(v, D_8013821A, 5);
    func_8003C780();
    return r;
}
