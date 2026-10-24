typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 D_801929F0[16];
extern u32 D_80192A2C;
extern u8 D_80192A30;

extern void func_80050A20(void);
extern void func_80050A64(void);
extern void func_80050D4C(void);
extern s32 func_800521B0(s32 direction, void *dram_addr);
extern s32 func_8004E540(void *queue, void *message, s32 flag);

s32 func_80050BE0(void *queue) {
    s32 result = 0;
    int i;

    func_80050A20();
    if (D_80192A30 != 1) {
        func_80050D4C();
        result = func_800521B0(1, D_801929F0);
        func_8004E540(queue, 0, 1);
    }
    for (i = 0; i < 16; i++) {
        D_801929F0[i] = 0xFF;
    }
    D_80192A2C = 0;
    result = func_800521B0(0, D_801929F0);
    D_80192A30 = 1;
    func_80050A64();
    return result;
}
