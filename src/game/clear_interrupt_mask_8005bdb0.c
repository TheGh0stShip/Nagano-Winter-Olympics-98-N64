extern unsigned int D_8007C9A0;
extern unsigned int func_8005BFD0(void);
extern void func_8005BFF0(unsigned int mask);

void func_8005BDB0(unsigned int value) {
    register unsigned int mask = func_8005BFD0();

    D_8007C9A0 &= ~(value & 0xFFFFFBFE);
    func_8005BFF0(mask);
}
