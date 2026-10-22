typedef struct StreamRecord {
    unsigned char pad[0x49];
    unsigned char mode;
    unsigned short count;
    unsigned short saved;
    unsigned char pad_4e[2];
    unsigned short next_saved;
    unsigned short alternate;
    unsigned short step;
} StreamRecord;

extern StreamRecord *D_80179924;
extern void func_8004B3E0(void);
extern void func_8004B86C(void);

void func_8004B800(void) {
    if (D_80179924->step != 0) {
        D_80179924->mode = 1;
        D_80179924->count -= D_80179924->step;
        D_80179924->saved = D_80179924->next_saved;
        func_8004B3E0();
    } else {
        func_8004B86C();
    }
}
