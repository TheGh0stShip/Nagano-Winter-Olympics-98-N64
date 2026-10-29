typedef struct InitBlock {
    int words[30];
} InitBlock;

extern InitBlock D_800690E0;
extern unsigned char *D_80126BF0;
extern short D_8006350C;
extern unsigned char D_80063504;
extern unsigned char D_8008F3D1;
extern void func_800036F8(int arg);
extern void func_800138C4(void);
extern void func_8005C650(int arg);
extern void func_8000D930(void);
extern int func_8000E5C4(void);
extern void func_80001B7C(int arg);

void func_80001F04(void) {
    static unsigned char D_8008F3D2 = 0;
    signed char result;

    *(short *)(D_80126BF0 + 0x7C8CA) = 1;
    *(InitBlock *)(D_80126BF0 + 0x7FFD8) = D_800690E0;
    D_80063504 = 0;
    switch (D_8006350C) {
    case 0:
        func_800036F8(0);
        func_800138C4();
        D_8008F3D1 = 1;
        func_8005C650(10);
        func_8000D930();
        D_8006350C = 1;
        break;
    case 2:
        D_8006350C = 3;
        D_8008F3D2 = 0;
        break;
    case 3:
        if (D_8008F3D2++ >= 6) {
            D_8006350C = 1;
            D_8008F3D2 = 0;
        }
        break;
    case 1:
        result = func_8000E5C4();
        if (result == 1) {
            func_80001B7C(6);
        }
        if (result < 0) {
            func_80001B7C(3);
        }
        if (result == 2) {
            func_80001B7C(5);
        }
        if (result == 3) {
            func_80001B7C(7);
        }
        break;
    default:
        D_8006350C = 0;
        break;
    }
}
