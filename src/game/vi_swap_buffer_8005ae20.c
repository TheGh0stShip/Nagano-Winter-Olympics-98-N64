typedef struct ViContext {
    unsigned short state;
    unsigned short retrace_count;
    void *framebuffer;
} ViContext;

extern ViContext *D_8007DA94;
extern unsigned int func_8005BFD0(void);
extern void func_8005BFF0(unsigned int mask);

void func_8005AE20(void *framebuffer) {
    unsigned int mask = func_8005BFD0();

    D_8007DA94->framebuffer = framebuffer;
    D_8007DA94->state |= 0x10;
    func_8005BFF0(mask);
}
