typedef unsigned long long u64;
typedef unsigned char u8;
extern u8 D_80072AF8;
extern u8 D_80138215;
extern u8 D_80137871;
extern u8 D_80137DE8;
extern u64 D_8007C990;
u64 D_80137888;
extern int D_80137D70[];
extern u8 D_80137DC0[];
extern u64 func_8005B340(void);
extern u64 func_8004EF88(u64 a, u64 b);
extern u64 func_8004F088(u64 a, u64 b);
extern void func_80037C3C(void *p, int v);

u64 func_8003746C(void) {
    if (D_80072AF8 == 0) {
        return 0;
    }
    if (D_80138215 == 1) {
        return 0;
    }
    D_80137871 = 0;
    D_80137888 = func_8004EF88(func_8004F088(func_8004EF88(func_8005B340(), 1000), 1000000), D_8007C990);
    D_80137D70[2] = 3;
    D_80137D70[3] = 6;
    func_80037C3C(D_80137DC0, 0);
    D_80137DE8 = 60;
    return D_80137888;
}
