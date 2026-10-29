extern unsigned char *D_80126BF0;
extern short D_8006350C;
extern unsigned char D_80063504;
extern void func_80030908(void);
extern void func_80007E5C(void);
extern void func_8000C150(void);
extern void func_8000C470(void);
extern int func_8000C484(void);
extern void func_8000D930(void);
extern short func_8000D96C(void);
extern void func_80001B7C(int arg);

void func_80001DE0(void) {
    short result;

    *(short *)(D_80126BF0 + 0x7C8CA) = 0;
    D_80063504 = 1;
    switch (D_8006350C) {
    case 0:
        func_80030908();
        func_80007E5C();
        func_8000C150();
        func_8000C470();
        *(short *)(D_80126BF0 + 0x7C8CE) = 0;
        D_8006350C = 1;
        break;
    case 1:
        if ((short)func_8000C484() == 0) {
            D_8006350C = 2;
        }
        break;
    case 2:
        func_8000D930();
        D_8006350C = 3;
        break;
    case 3:
        result = func_8000D96C();
        if (result < 0) {
            func_80001B7C(4);
        }
        if (result > 0) {
            func_80001B7C(2);
        }
        break;
    default:
        D_8006350C = 0;
        break;
    }
}
