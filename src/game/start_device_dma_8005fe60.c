typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern u8 D_8007DBE0;
extern s32 func_8005FF10(void);
extern u32 func_800512C0(void *address);

s32 func_8005FE60(void *address, u32 size) {
    void *adjusted;

    adjusted = address;
    if (D_8007DBE0 != 0) {
        adjusted = (u8 *)address - 0x2000;
    }
    if ((((u32)address + size) & 0x3FFF) == 0x2000) {
        D_8007DBE0 = 1;
    } else {
        D_8007DBE0 = 0;
    }
    if (func_8005FF10() != 0) {
        return -1;
    }
    *(volatile u32 *)0xA4500000 = func_800512C0(adjusted);
    *(volatile u32 *)0xA4500004 = size;
    return 0;
}
