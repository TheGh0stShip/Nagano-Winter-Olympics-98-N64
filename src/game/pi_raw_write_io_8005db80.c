extern unsigned int D_80000308;

int func_8005DB80(unsigned int device_address, unsigned int value) {
    register unsigned int status;

    while ((status = *(volatile unsigned int *)0xA4600010) & 3) {
    }
    *(volatile unsigned int *)(0xA0000000 |
                               (D_80000308 | device_address)) = value;
    return 0;
}
