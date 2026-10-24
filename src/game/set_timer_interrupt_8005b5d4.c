extern unsigned int D_80194270;
extern unsigned int func_8005BFD0(void);
extern unsigned int func_80054380(void);
extern void func_8005BA10(unsigned int count);
extern void func_8005BFF0(unsigned int mask);

void func_8005B5D4(unsigned long long time) {
    unsigned long long new_time;
    unsigned int mask;

    mask = func_8005BFD0();
    D_80194270 = func_80054380();
    new_time = D_80194270 + time;
    func_8005BA10((unsigned int)new_time);
    func_8005BFF0(mask);
}
