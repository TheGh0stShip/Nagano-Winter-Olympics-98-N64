extern unsigned char *D_80126BF0;
extern unsigned char D_80071A68[];
extern void func_80048580(int);

void func_8002C32C(void) {
    unsigned char *runtime;

    runtime = D_80126BF0 + 0x90000;
    if (runtime[0x77EF] + 1 < runtime[0x77F0] ||
        (runtime[0x77F2] + 1 != D_80071A68[runtime[0x77EC]] &&
         runtime[0x77F1] != 21)) {
        func_80048580(7);
    }
}
