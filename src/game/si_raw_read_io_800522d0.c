extern int func_8005ABA0(void);

int func_800522D0(unsigned int address, unsigned int *value) {
    if (func_8005ABA0()) {
        return -1;
    }
    *value = *(volatile unsigned int *)(address | 0xA0000000);
    return 0;
}
