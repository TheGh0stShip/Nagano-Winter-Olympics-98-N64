typedef unsigned char u8;
typedef unsigned short u16;

typedef struct StreamCounterState {
    u8 pad0[0x22];
    u8 active;
    u8 pad23[0x26];
    u8 mode;
    u16 previous;
    u16 limit;
    u8 pad4E[4];
    u16 counter;
} StreamCounterState;

extern u8 *D_80179920;
extern StreamCounterState *D_80179924;
extern u16 D_80073ADE[];

void func_8004C00C(void) {
    int value = *D_80179920++;

    if (value == 0) {
        D_80179924->counter = 0;
        if (D_80179924->active == 0 && D_80179924->mode == 2) {
            D_80179924->limit = 0x7FFF;
        }
        return;
    }
    {
        u16 previous = D_80179924->counter;
        D_80179924->counter =
            *(u16 *)((u8 *)D_80073ADE + -(value << 1)) + 1;
        if (D_80179924->active == 0 && D_80179924->mode == 2) {
            D_80179924->limit = D_80179924->counter;
            if (previous == 0) {
                D_80179924->previous = 0;
            }
        }
    }
}
