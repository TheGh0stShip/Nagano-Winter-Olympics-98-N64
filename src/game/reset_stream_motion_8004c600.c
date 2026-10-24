typedef struct StreamRecord {
    unsigned char pad0[0x93];
    unsigned char current_mode;
    unsigned char previous_mode;
    unsigned char pad95;
    unsigned short counter;
    unsigned char counter_byte;
    unsigned char pad99;
    unsigned short limit;
    unsigned short remaining;
    unsigned char active;
    unsigned char previous_active;
} StreamRecord;

extern StreamRecord *D_80179924;

void func_8004C600(void) {
    D_80179924->previous_mode = D_80179924->current_mode;
    D_80179924->previous_active = D_80179924->active;
    if (D_80179924->active == 0) {
        D_80179924->remaining = D_80179924->limit;
    } else {
        D_80179924->remaining = 0;
    }
    D_80179924->counter = 0;
    D_80179924->counter_byte = D_80179924->counter;
}
