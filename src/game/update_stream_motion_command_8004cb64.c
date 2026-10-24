typedef struct StreamRecord {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x21];
    int current;
    unsigned char pad2C[0x50];
    unsigned char delay;
    unsigned char steps;
    unsigned char pad7E[2];
    int target;
    int increment;
    unsigned char pad88[4];
    unsigned char enabled;
} StreamRecord;

extern StreamRecord *D_80179924;

extern void func_8004CD9C(void);

void func_8004CB64(void) {
    if (D_80179924->enabled == 0) {
        if (D_80179924->delay != 0) {
            D_80179924->delay--;
            return;
        }

        D_80179924->flags |= 2;
        D_80179924->steps--;
        if (D_80179924->steps != 0) {
            D_80179924->current += D_80179924->increment;
        } else {
            D_80179924->current = D_80179924->target;
        }
    } else {
        func_8004CD9C();
    }
}
