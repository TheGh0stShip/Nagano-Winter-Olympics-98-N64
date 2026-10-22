typedef struct StreamRecord {
    unsigned char pad_00[0x0F];
    unsigned char active;
    unsigned char pad_10[0x39];
    unsigned char mode;
    unsigned short count;
    unsigned short saved;
} StreamRecord;

extern StreamRecord *D_80179924;
extern void func_8004B3E0(void);

void func_8004B900(void) {
    D_80179924->active = 1;
    D_80179924->mode = 3;
    D_80179924->count = 0;
    D_80179924->saved = 1;
    func_8004B3E0();
}
