typedef struct StreamRecord {
    unsigned char pad0[0x28];
    int current;
    unsigned char pad2C[0x50];
    unsigned char delay;
    unsigned char steps;
    unsigned char pad7E[2];
    int target;
    int increment;
    unsigned char first;
    unsigned char second;
    short value;
    unsigned char enabled;
} StreamRecord;

extern StreamRecord *D_80179924;

extern void func_8004C9E4(void);

void func_8004CCD0(void) {
    if (D_80179924->enabled == 0) {
        D_80179924->delay = D_80179924->first;
        D_80179924->steps = D_80179924->second;
        D_80179924->target = D_80179924->current;
        D_80179924->current -= D_80179924->value;
        func_8004C9E4();
    } else {
        D_80179924->target = D_80179924->current;
        D_80179924->current = D_80179924->increment;
        D_80179924->steps = 1;
    }
}
