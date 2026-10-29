extern int D_80137700;
extern unsigned char D_80137704;
extern short D_80137706;
extern short D_80137708;
extern unsigned char D_80137710;
extern unsigned char D_8006E590;

extern int func_80005C48(void);
extern int func_8003227C(void);
extern int func_800322D4(void);
extern short func_800322DC(void);
extern int func_80032304(void);
extern void func_800323F4(void);
extern void func_80030DE8(void);
extern signed char func_80030F70(void);
extern void func_80030EEC(unsigned char mode, float value);
extern int func_800349F0(void);
extern int func_80034A44(void);
extern void func_8000A2F0(void);
extern void func_800348FC(int arg);

signed char func_80032074(unsigned char arg) {
    int pad[1];
    short pad2;
    signed char result = 0;

    D_80137704 = arg;
    func_80005C48();
    pad2 = func_80005C48();
    switch (D_80137700) {
    case 0:
        if (func_8003227C()) {
            func_80030DE8();
            D_80137710 = 1;
            D_80137700 = 1;
        }
        break;
    case 1:
        if (func_800322D4()) {
            D_80137700 = 2;
        }
        break;
    case 2:
        D_80137708 = func_800322DC();
        if (D_80137708 != 0) {
            if (func_800349F0() && D_80137708 > 0 && D_8006E590 == 3) {
                D_80137700 = 3;
            } else {
                D_80137700 = 4;
            }
            D_80137706 = 0;
        }
        break;
    case 3:
        if (func_80034A44()) {
            D_80137700 = 6;
            func_8000A2F0();
            D_80137706 = 0;
        }
        break;
    case 4:
        if (func_80032304()) {
            D_80137700 = 6;
            D_80137706 = 0;
        }
        break;
    case 6:
        if (D_80137710 == 0) {
            func_800323F4();
            if (D_80137708 > 0) {
                result = 1;
            } else if (D_80137708 < 0) {
                result = D_80137708;
            }
        } else {
            func_800348FC(0);
        }
        break;
    case 5:
    default:
        D_80137700 = 6;
        break;
    }
    D_80137710 = func_80030F70();
    if (result != 0) {
        func_80030EEC(6, 3.0f);
        D_80137710 = 1;
    }
    return result;
}
