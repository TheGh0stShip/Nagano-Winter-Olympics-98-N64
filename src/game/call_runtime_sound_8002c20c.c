extern unsigned char *D_80126BF0;
extern unsigned char D_80071B1C[];
extern unsigned short D_80071B34[][4];
extern void func_80048580(unsigned short);

void func_8002C20C(void) {
    unsigned char *runtime;
    unsigned char row;

    runtime = D_80126BF0 + 0x90000;
    if (runtime[0x77F0] != 1) {
        row = D_80071B1C[runtime[0x77EC]];
        func_80048580(D_80071B34[row][runtime[0x77EF]]);
    }
}
