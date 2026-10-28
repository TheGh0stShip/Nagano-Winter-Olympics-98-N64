typedef unsigned int u32;
typedef int s32;

extern s32 func_8005ABA0(void);
extern u32 func_800512C0(void *address);
extern void func_80051340(void *address, s32 size);
extern void func_8005A600(void *address, s32 size);

s32 func_800521B0(s32 direction, void *dramAddress) {
    if (func_8005ABA0()) {
        return -1;
    }
    if (direction == 1) {
        func_80051340(dramAddress, 0x40);
    }
    *(volatile u32 *)0xA4800000 = func_800512C0(dramAddress);
    if (direction == 0) {
        *(volatile u32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(volatile u32 *)0xA4800010 = 0x1FC007C0;
    }
    if (direction == 0) {
        func_8005A600(dramAddress, 0x40);
    }
    return 0;
}
