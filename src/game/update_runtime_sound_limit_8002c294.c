extern unsigned char *D_80126BF0;
extern unsigned char D_80071A68[];
extern void func_80048580(int);
extern void func_8002C414(void);

void func_8002C294(void) {
    unsigned char *runtime;

    runtime = D_80126BF0 + 0x90000;
    if (runtime[0x77EF] + 1 >= runtime[0x77F0]) {
        if (runtime[0x77F2] + 1 == D_80071A68[runtime[0x77EC]]) {
            func_80048580(1);
            func_8002C414();
        } else if (runtime[0x77F1] == 21) {
            func_80048580(1);
            func_8002C414();
        }
    }
}
