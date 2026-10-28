typedef struct StreamRecord {
    unsigned char pad0[0x58];
    unsigned short value;
    unsigned char target;
    unsigned char counter;
    short delta;
} StreamRecord;

extern StreamRecord *D_80179924;
extern unsigned char D_8017966C;
extern void func_8004A250(unsigned char);

void func_8004C390(void) {
    unsigned short high;
    int value;

    high = D_80179924->value & 0x8000;
    D_80179924->counter--;
    if (D_80179924->counter != 0) {
        value = D_80179924->value & 0x7FFF;
        value += D_80179924->delta;
        if (value < 0) {
            value = 0;
        } else if (value >= 0x8000) {
            value = 0x7F00;
        }
        D_80179924->value = value;
    } else {
        D_80179924->value = D_80179924->target << 8;
    }
    D_80179924->value |= high;
    func_8004A250(D_8017966C);
}
