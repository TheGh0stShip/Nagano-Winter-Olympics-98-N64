typedef struct StreamRecord {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x21];
    int current;
    unsigned char pad2C[0x50];
    unsigned char delay;
    unsigned char pad7D[7];
    int increment;
    unsigned char pad88[4];
    unsigned char enabled;
} StreamRecord;

extern StreamRecord *D_80179924;

extern void func_8004CD9C(void);

void func_8004CBFC(void) {
    if (D_80179924->enabled == 0) {
        if (D_80179924->delay != 0) {
            return;
        }
        D_80179924->flags |= 2;
        D_80179924->current += D_80179924->increment;
    } else {
        func_8004CD9C();
    }
}
