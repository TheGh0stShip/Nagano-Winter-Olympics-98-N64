extern unsigned char *D_80126BF0;
extern void func_80048580(int);
extern void func_8002C414(void);

void func_8002C3A4(void) {
    unsigned char *runtime;

    runtime = D_80126BF0 + 0x90000;
    if (runtime[0x77EF] != 0 || runtime[0x77F2] != 0) {
        func_80048580(1);
    }
    func_8002C414();
}
