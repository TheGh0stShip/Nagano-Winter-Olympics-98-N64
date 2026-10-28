typedef struct StreamRecord {
    unsigned char pad_00[0x0F];
    unsigned char active;
    unsigned char pad_10[0x39];
    unsigned char mode;
    unsigned short count;
    unsigned short saved;
    unsigned char pad_4E[0x60];
    unsigned short delay;
} StreamRecord;

extern StreamRecord *D_80179924;
extern void func_8004B3E0(void);
extern void func_8004B800(void);
extern void func_8004B86C(void);

void func_8004B900(void) {
    D_80179924->active = 1;
    D_80179924->mode = 3;
    D_80179924->count = 0;
    D_80179924->saved = 1;
    func_8004B3E0();
}

void func_8004B94C(void) {
    D_80179924->saved--;
    if (D_80179924->delay != 0) {
        D_80179924->delay--;
    }
    if (D_80179924->saved == 0) {
        switch (D_80179924->mode) {
            case 0:
                func_8004B800();
                break;
            case 1:
                func_8004B86C();
                break;
        }
    }
}
