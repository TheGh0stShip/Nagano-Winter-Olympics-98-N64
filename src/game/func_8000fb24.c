extern int D_80134010;
extern unsigned char D_80134014;
extern short D_80134016;
extern int D_80134018;
extern unsigned char D_8008F3D1;
extern int func_80030F70(void);
extern int func_8000FDB0(void);
extern void func_80030DE8(void);
extern void func_800485AC(int arg0);
extern int func_8000FDFC(void);
extern void func_800106E4(int arg0);
extern int func_800105A4(void);
extern int func_80010048(void);
extern int func_8001049C(void);

int func_8000FB24(void) {
    signed char result;
    int status;

    D_80134014 = func_80030F70();
    switch (D_80134010) {
    case 0:
        if (func_8000FDB0()) {
            D_80134010 = 1;
            func_80030DE8();
            if (D_8008F3D1) {
                func_800485AC(0x1E);
                D_8008F3D1 = 0;
            }
        }
        break;
    case 1:
        if (func_8000FDFC()) {
            D_80134010 = 5;
            D_80134018 = 0;
            func_800106E4(0);
        }
        break;
    case 5:
        status = func_800105A4();
        if (status < 0) {
            return -1;
        }
        if (status > 0) {
            D_80134010 = 2;
            if (D_80134016 != 4) {
                D_8008F3D1 = 1;
            }
            D_80134018 = 0;
        }
        break;
    case 2:
        if (func_80010048()) {
            D_80134010 = 3;
        }
        break;
    case 3:
        if (D_80134014 != 0) {
            break;
        }
        result = status = func_8001049C();
        if (status < 0) {
            D_80134010 = 1;
        }
        return result;
    case 4:
    default:
        D_80134010 = 3;
        break;
    }
    return 0;
}
