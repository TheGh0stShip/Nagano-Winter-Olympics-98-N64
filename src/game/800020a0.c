typedef struct InitBlock {
    int words[30];
} InitBlock;

extern InitBlock D_800690E0;
extern unsigned char *D_80126BF0;
extern short D_8006350C;
extern void func_8005C650(int arg);
extern void func_800138C4(void);
extern void func_8000D930(void);
extern int func_8000DBAC(void);
extern void func_80007E5C(void);
extern void func_80001B7C(int arg);

void func_800020A0(void) {
    *(short *)(D_80126BF0 + 0x7C8CA) = 1;
    *(InitBlock *)(D_80126BF0 + 0x7FFD8) = D_800690E0;
    switch (D_8006350C) {
    case 0:
        func_8005C650(10);
        func_800138C4();
        func_8000D930();
        D_8006350C = 1;
        break;
    case 1:
        if ((short)func_8000DBAC() > 0) {
            func_80007E5C();
            func_80001B7C(4);
        }
        break;
    default:
        D_8006350C = 0;
        break;
    }
}
