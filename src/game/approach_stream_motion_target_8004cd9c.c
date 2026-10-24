typedef struct StreamRecord {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x21];
    int current;
    unsigned char pad2C[0x51];
    unsigned char steps;
    unsigned char pad7E[2];
    int target;
    unsigned char pad84[6];
    short scale;
} StreamRecord;

extern StreamRecord *D_80179924;

void func_8004CD9C(void) {
    int difference;
    int amount;

    D_80179924->flags |= 2;
    difference = D_80179924->target - D_80179924->current;
    amount = difference;
    if (amount < 0) {
        amount = -amount;
    }
    amount = (D_80179924->scale * amount) >> 8;
    if (amount == 0) {
        amount = 1;
    }

    if (difference < 0) {
        D_80179924->current -= amount;
        if (D_80179924->current < D_80179924->target) {
            D_80179924->current = D_80179924->target;
        }
    } else {
        D_80179924->current += amount;
        if (D_80179924->current > D_80179924->target) {
            D_80179924->current = D_80179924->target;
        }
    }

    if (D_80179924->current == D_80179924->target) {
        D_80179924->steps = 0;
    }
}
