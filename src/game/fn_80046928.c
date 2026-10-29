extern unsigned char *D_80126BF0;
extern int D_80138640;
extern int D_80138644;
extern int D_80138694;
extern void func_80030DE8(void);
extern void func_80030E0C(void);
extern void func_80030E30(void);
extern void func_80030E54(void);
extern int func_80030F70(void);

void func_80046928(void) {
    switch (D_80138640) {
    case 1:
        if (D_80138640 != D_80138644) {
            if (D_80126BF0[0x977F8] == 0) {
                func_80030DE8();
            } else {
                func_80030E0C();
            }
            D_80138694 = 0;
        }
        if (func_80030F70() != 2) {
            if (func_80030F70() != 1) {
                D_80138694++;
                if (D_80138694 >= 8) {
                    D_80138640 = 2;
                }
            }
        }
        break;
    case 3:
        if (D_80138640 != D_80138644) {
            if (D_80126BF0[0x977F8] == 0) {
                func_80030E30();
            } else {
                func_80030E54();
            }
            D_80138694 = 0;
        }
        if (func_80030F70() != 2) {
            if (func_80030F70() != 1) {
                D_80138694++;
                if (D_80138694 >= 8) {
                    D_80138640 = 4;
                }
            }
        }
        break;
    case 0:
    case 2:
    case 4:
    default:
        break;
    }
    D_80138644 = D_80138640;
}
