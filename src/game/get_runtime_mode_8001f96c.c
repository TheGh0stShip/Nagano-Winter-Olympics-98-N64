extern unsigned char *D_80126BF0;
extern unsigned int func_80030F70(void);

unsigned int func_8001F96C(void) {
    if (func_80030F70() != 2) {
        D_80126BF0[0x977F6] = 0;
        return 4;
    }
    return D_80126BF0[0x977F6];
}
