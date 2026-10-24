int func_8005FF10(void) {
    register unsigned int status = *(volatile unsigned int *)0xA450000C;

    if (status & 0x80000000) {
        return 1;
    }
    return 0;
}
