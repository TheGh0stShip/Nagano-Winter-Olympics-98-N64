int func_8005ABA0(void) {
    register unsigned int status = *(volatile unsigned int *)0xA4800018;

    if (status & 3) {
        return 1;
    }
    return 0;
}
