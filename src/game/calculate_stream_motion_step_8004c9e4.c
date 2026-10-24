typedef struct StreamRecord {
    unsigned char pad0[0x18];
    unsigned short divisor;
    unsigned char pad1A[0x0E];
    int current;
    unsigned char pad2C[0x51];
    unsigned char rate;
    unsigned char pad7E[2];
    int target;
    int increment;
} StreamRecord;

extern StreamRecord *D_80179924;

void func_8004C9E4(void) {
    int steps;
    int difference;

    steps = (unsigned short)((((unsigned int)D_80179924->rate << 16) /
                              D_80179924->divisor) + 1);
    difference = D_80179924->target - D_80179924->current;
    D_80179924->increment = difference / steps;
    if (D_80179924->increment == 0) {
        if (difference < 0) {
            D_80179924->increment--;
        } else {
            D_80179924->increment++;
        }
    }
}
