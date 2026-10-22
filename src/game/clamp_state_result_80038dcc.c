extern unsigned char *D_80126BF0;
extern int func_80038E0C(unsigned char);

int func_80038DCC(void) {
    int result = func_80038E0C(D_80126BF0[0x977EF]);

    if (result < 0) {
        result = 15;
    }
    return result;
}
