extern int func_8005ABA0(void);

int func_8005F380(unsigned int address, unsigned int value) {
    if (func_8005ABA0()) {
        return -1;
    }
    *(volatile unsigned int *)(address | 0xA0000000) = value;
    return 0;
}
