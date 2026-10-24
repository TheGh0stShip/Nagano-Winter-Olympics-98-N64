typedef struct StreamRecord {
    unsigned char pad0[0x94];
    unsigned char mode_delay;
    unsigned char pad95[4];
    unsigned char pad99;
    unsigned short limit;
    unsigned short remaining;
    unsigned char pad9E;
    unsigned char active_delay;
    unsigned short increment;
} StreamRecord;

extern StreamRecord *D_80179924;

extern void func_8004C6D4(void);

void func_8004C658(void) {
    if (D_80179924->mode_delay != 0) {
        D_80179924->mode_delay--;
        return;
    }

    if (D_80179924->active_delay != 0) {
        D_80179924->active_delay--;
        if (D_80179924->active_delay != 0) {
            D_80179924->remaining += D_80179924->increment;
        } else {
            D_80179924->remaining = D_80179924->limit;
        }
    }
    func_8004C6D4();
}
