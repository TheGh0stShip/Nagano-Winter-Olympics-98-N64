typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct ContStatus {
    u16 type;
    u8 status;
    u8 error;
} ContStatus;

u8 D_80192EA0[64];
extern void func_80053DC0(u8 command);
extern s32 func_800521B0(s32 direction, void *dramAddress);
extern s32 func_8004E540(void *queue, void **message, s32 flag);
extern void func_80053EBC(u8 *pattern, ContStatus *data);

s32 func_8005CFC0(void *queue, s32 channel) {
    s32 result = 0;
    void *message;
    u8 pattern;
    ContStatus data[4];

    func_80053DC0(0);
    result = func_800521B0(1, D_80192EA0);
    func_8004E540(queue, &message, 1);
    result = func_800521B0(0, D_80192EA0);
    func_8004E540(queue, &message, 1);
    func_80053EBC(&pattern, data);
    if ((data[channel].status & 1) != 0 && (data[channel].status & 2) != 0) {
        return 2;
    }
    if (data[channel].error != 0 || (data[channel].status & 1) == 0) {
        return 1;
    }
    if ((data[channel].status & 4) != 0) {
        return 4;
    }
    return result;
}
