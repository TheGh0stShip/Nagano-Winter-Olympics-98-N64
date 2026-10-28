typedef struct StreamRecord {
    unsigned char pad0[0x49];
    unsigned char mode;
    unsigned short count;
    unsigned short saved;
    unsigned short next;
} StreamRecord;

extern StreamRecord *D_80179924;
extern void func_8004B3E0(void);
extern void func_8004B800(void);

void func_8004B774(void) {
    D_80179924->saved = 0;
    if (D_80179924->next != 0) {
        D_80179924->count = 0x20;
        func_8004B3E0();
        D_80179924->mode = 0;
        D_80179924->count = 0x100;
        D_80179924->saved = D_80179924->next;
        func_8004B3E0();
    } else {
        D_80179924->count = 0x100;
        func_8004B3E0();
        func_8004B800();
    }
}
