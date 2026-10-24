typedef signed int s32;
typedef unsigned char u8;

extern u8 D_801929F0[];
extern u8 D_80192A30;

extern void func_80050A20(void);
extern void func_80050A64(void);
extern void func_800508D8(u8 command);
extern s32 func_800521B0(s32 direction, void *dram_addr);
extern s32 func_8004E540(void *queue, void *message, s32 flag);

s32 func_80059620(void *queue) {
    s32 result = 0;

    func_80050A20();
    if (D_80192A30 != 0) {
        func_800508D8(0);
        result = func_800521B0(1, D_801929F0);
        func_8004E540(queue, 0, 1);
    }
    result = func_800521B0(0, D_801929F0);
    D_80192A30 = 0;
    func_80050A64();
    return result;
}
