int func_8005FF80(unsigned int address) {
    register unsigned int status = *(volatile unsigned int *)0xA4040010;

    if (!(status & 1)) {
        return -1;
    }
    *(volatile unsigned int *)0xA4080000 = address;
    return 0;
}
