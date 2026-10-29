typedef unsigned long long u64;
typedef unsigned char u8;

extern u8 D_80138215;
extern u8 D_80137870;
extern u8 D_80137DE8;
extern u8 *D_80126BF0;
extern u64 D_8007C990;
long long D_80137880;
extern long long D_80137878;
long long D_80137888;
extern u8 D_80137D30[];

extern u64 func_8005B340(void);
extern u64 func_8004EF88(u64 a, u64 b);
extern u64 func_8004F088(u64 a, u64 b);
extern long long func_8004F02C(long long a, long long b);
extern float func_8005426C(long long value);
extern float func_80029CB8(float value);
extern u64 func_800540FC(float value);
extern void func_800366E0(long long value);
extern u64 func_8003746C(void);
extern float func_8002A7E0(void);
extern void func_80036F40(void *object, float value);

long long func_800370E0(void) {
    unsigned char pad[0x28];
    long long result;

    if (D_80138215 == 1) {
        return 0;
    }
    D_80137870 = 0;
    D_80137880 = func_8004EF88(func_8004F088(func_8004EF88(func_8005B340(), 1000), 1000000), D_8007C990);
    switch (*(D_80126BF0 + 0x977EC)) {
    case 0:
    case 1:
    case 6:
    case 7:
    case 8:
    case 9:
        D_80137880 = func_8004F088(func_8004F02C(D_80137880, 10), 10);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 10:
        break;
    }
    D_80137880 = func_800540FC(func_80029CB8(func_8005426C(D_80137880)));
    if (D_80137878 > (result = D_80137880)) {
        func_800366E0(result);
    }
    func_8003746C();
    result = D_80137880;
    D_80137888 = result;
    switch (*(D_80126BF0 + 0x977EC)) {
    case 0:
    case 1:
    case 6:
    case 8:
    case 9:
    case 10:
        D_80137DE8 = 0x3D;
        break;
    case 7:
        D_80137DE8 = 0x3E;
        if (*(D_80126BF0 + 0x977F2) == 1) {
            D_80137DE8 = 0x3F;
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
    if (*(D_80126BF0 + 0x977F1) == 0x15) {
        func_80036F40(D_80137D30, func_8002A7E0());
        D_80137DE8 = 0x40;
        result = D_80137880;
    }
    return result;
}
