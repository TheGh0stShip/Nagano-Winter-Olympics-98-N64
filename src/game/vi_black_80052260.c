typedef struct ViContext {
    unsigned short state;
} ViContext;

extern ViContext *D_8007DA94;
extern unsigned int func_8005BFD0(void);
extern void func_8005BFF0(unsigned int mask);

void func_80052260(unsigned char active) {
    register unsigned int mask = func_8005BFD0();

    if (active) {
        D_8007DA94->state |= 0x20;
    } else {
        D_8007DA94->state &= ~0x20;
    }
    func_8005BFF0(mask);
}
