extern unsigned short D_80063508;
extern unsigned short D_8006350C;
extern unsigned short D_80063510;
extern void func_80007E5C(void);
extern void func_800036F8(int);

void func_80001BB8(void) {
    D_80063508 = 0;
    D_8006350C = 0;
    D_80063510 = 0;
    func_80007E5C();
    func_800036F8(0);
}
