extern void func_800282B0(void);
extern float func_8002AACC(void);
extern void func_8002C20C(void);
extern void func_800366E0(long long);
extern void func_80037B10(void);
extern void func_80038C18(int);
extern void func_80038E88(unsigned char);
extern void func_80039004(int, float, float, int, void *, int);
extern unsigned char func_800390B4(unsigned char, int, unsigned char *, int);
extern void func_80039788(void);
extern void func_80039A8C(void);
extern void func_8003A120(void);
extern void func_8003A5C8(int, int, int);
extern int func_8003B044(int);
extern int func_8003B694(int, int, unsigned char *, int);
extern int func_8003C6B4(int);
extern long long func_800540FC(float);
extern unsigned char D_80072AF8;
extern unsigned char *D_80126BF0;
extern float D_801374B8;
extern unsigned char D_801381F0;
extern unsigned char D_801381F1;
extern unsigned char D_80138214;
extern int D_80072FF4[];
extern char D_06013518[];

int func_80039340(void) {
    int k;
    int n;
    int ret;
    unsigned char m;
    if (D_80072AF8 == 0) {
        return 0;
    }
    ret = func_8003C6B4(1);
    if (ret == 1) {
        return 1;
    }
    func_80037B10();
    m = D_80126BF0[0x977EC];
    if (m != 4 && m != 5) {
        func_8002C20C();
    }
    D_80138214 = 1;
    func_800282B0();
    func_800366E0(func_800540FC(func_8002AACC()));
    if (D_80126BF0[0x977EC] == 7 && D_80126BF0[0x977F1] != 0x15) {
        func_800366E0(func_800540FC(D_801374B8));
    }
    func_80038E88(D_80126BF0[0x977EC]);
    func_80038C18(0);
    func_8003A120();
    n = func_8003B044(0x19);
    func_80039004(n++, 0.0f, 0.0f, 7, D_06013518, 1);
    D_801381F0 = n;
    D_801381F1 = 0;
    D_801381F1 = func_800390B4(D_801381F0, D_80072FF4[D_80126BF0[0x977EC]], &D_801381F0, n);
    k = func_8003B694(n + (unsigned int)D_801381F1, 0, &D_801381F1, n);
    if (D_80126BF0[0x977F1] != 0x15) {
        func_8003A5C8(k, 0, 5);
    }
    func_80039A8C();
    func_80039788();
    return ret;
}
