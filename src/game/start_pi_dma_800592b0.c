typedef unsigned int u32;
typedef int s32;

extern u32 D_80000308;
extern u32 func_800512C0(void *address);

s32 func_800592B0(s32 direction, u32 deviceAddress, void *dramAddress,
                  u32 size) {
    register u32 status;

    while ((status = *(volatile u32 *)0xA4600010) & 3) {
    }
    *(volatile u32 *)0xA4600000 = func_800512C0(dramAddress);
    *(volatile u32 *)0xA4600004 =
        (D_80000308 | deviceAddress) & 0x1FFFFFFF;
    switch (direction) {
        case 0:
            *(volatile u32 *)0xA460000C = size - 1;
            break;
        case 1:
            *(volatile u32 *)0xA4600008 = size - 1;
            break;
        default:
            return -1;
    }
    return 0;
}
