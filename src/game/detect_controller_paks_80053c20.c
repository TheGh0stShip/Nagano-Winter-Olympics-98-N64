typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
typedef struct ContStatus { u16 type; u8 status; u8 error; } ContStatus;
extern u8 D_80192A31;
extern u8 D_80192EA0[64];
extern void func_80050A20(void); extern void func_80050A64(void);
extern void func_80053DC0(u8 command); extern s32 func_800521B0(s32, void *);
extern s32 func_8004E540(void *, void **, s32); extern void func_80053EBC(u8 *, ContStatus *);

s32 func_80053C20(void *queue, u8 *pattern) {
    s32 result = 0;
    void *message;
    u8 bitPattern;
    ContStatus data[4];
    int channel;
    u8 bits = 0;
    int retries = 3;
    func_80050A20();
    while (1) {
        func_80053DC0(0);
        result = func_800521B0(1, D_80192EA0);
        func_8004E540(queue, &message, 1);
        result = func_800521B0(0, D_80192EA0);
        func_8004E540(queue, &message, 1);
        func_80053EBC(&bitPattern, data);
        for (channel = 0; channel < D_80192A31; channel++) {
            if ((data[channel].status & 4) == 0) { retries--; break; }
        }
        if (D_80192A31 == channel) retries = 0;
        if (retries < 1) break;
    }
    for (channel = 0; channel < D_80192A31; channel++) {
        if (data[channel].error == 0 && (data[channel].status & 1) != 0) bits |= 1 << channel;
    }
    func_80050A64();
    *pattern = bits;
    return result;
}
