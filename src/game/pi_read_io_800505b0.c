extern unsigned int D_80000308;

int func_800505B0(unsigned int device_address, unsigned int *value) {
    register unsigned int status;

    while ((status = *(volatile unsigned int *)0xA4600010) & 3) {
    }
    *value = *(volatile unsigned int *)(D_80000308 | device_address |
                                       0xA0000000);
    return 0;
}
