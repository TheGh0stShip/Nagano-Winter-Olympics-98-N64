extern unsigned int func_8005BFD0(void);
extern unsigned int func_80054380(void);
extern void func_8005BFF0(unsigned int mask);
extern unsigned int D_80194268;
extern unsigned long long D_80194260;

unsigned long long func_8005B340(void) {
    unsigned int tmptime;
    unsigned int elapseCount;
    unsigned long long currentCount;
    register unsigned int saveMask;

    saveMask = func_8005BFD0();
    tmptime = func_80054380();
    elapseCount = tmptime - D_80194268;
    currentCount = D_80194260;
    func_8005BFF0(saveMask);
    return currentCount + elapseCount;
}
