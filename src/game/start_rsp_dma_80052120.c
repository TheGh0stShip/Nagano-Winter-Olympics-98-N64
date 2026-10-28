extern int func_8005AB70(void);
extern unsigned int func_800512C0(void *address);

int func_80052120(int direction, unsigned int devAddr, void *dramAddr, unsigned int size) {
    if (func_8005AB70()) {
        return -1;
    }
    *(volatile unsigned int *)0xA4040000 = devAddr;
    *(volatile unsigned int *)0xA4040004 = func_800512C0(dramAddr);
    if (direction == 0) {
        *(volatile unsigned int *)0xA404000C = size - 1;
    } else {
        *(volatile unsigned int *)0xA4040008 = size - 1;
    }
    return 0;
}
