extern unsigned char D_80138214;
extern signed char D_8013821A;
extern unsigned char D_8013820C;
extern unsigned char D_801380B8;
extern float D_801381F8;
extern float D_80138204;
extern unsigned char *D_80126BF0;

extern int func_8003DCBC(void);
extern int func_8003CA5C(int, int);
extern void func_8003CA14(void);
extern int func_80039B24(void);
extern int func_8003CBA0(int, int);
extern void func_8003CF4C(int);
extern int func_8003CC78(void);
extern void func_8003C5C8(int, int, int);
extern void func_8003CD94(int);
extern void func_8003CFE4(int);
extern int func_8003D06C(void);
extern float func_8003CE68(void);
extern float func_8003CECC(void);
extern void func_8003D0F0(float);
extern void func_8003CB80(void);
extern void func_8003D170(void);
extern void func_8003D190(void);
extern int func_8003CB44(void);

int func_8003C780(void) {
    int pad;
    int ret;
    int r;
    float f;

    ret = 0;
    if (D_80138214 == 5 || D_80138214 == 7) {
        if (func_8003DCBC() == 1) {
            if (D_80138214 == 5) {
                func_8003CA5C(4, D_8013821A);
            }
            if (D_80138214 == 7) {
                func_8003CA14();
            }
            D_801381F8 = 3.769f;
            func_80039B24();
            D_801380B8 = 9;
        } else {
            return 0;
        }
    }
    switch (D_801380B8) {
    case 0:
        D_801381F8 += 0.047123891676382035;
        if (func_80039B24() == 0) {
            D_801380B8 = 1;
        }
        break;
    case 1:
        r = func_8003CBA0(5, 4);
        if (r & 0x4000) {
            D_801380B8 = 5;
        }
        if (D_80126BF0[0x977EC] == 0xB && (r & 0x1000000)) {
            D_80138204 = 1.5707964f;
            D_801380B8 = 7;
        }
        break;
    case 2:
        func_8003CF4C(5);
        break;
    case 3:
        if (func_8003CC78()) {
            func_8003C5C8(D_8013820C, D_8013821A, 5);
            func_8003CD94(5);
        }
        break;
    case 4:
        func_8003CFE4(5);
        break;
    case 5:
        if (func_8003D06C()) {
            ret = 1;
        }
        break;
    case 7:
        f = func_8003CE68();
        func_8003D0F0(f);
        if (f >= 1.0f) {
            func_8003CB80();
            if (D_80138214 == 4) {
                func_8003D170();
                return 0;
            }
            func_8003D190();
            return 0;
        }
        break;
    case 9:
        f = func_8003CECC();
        func_8003D0F0(f);
        break;
    }
    func_8003CB44();
    if (ret == 1) {
        func_8003CB80();
    }
    return ret;
}
