typedef struct StreamRecord {
    unsigned char pad[0x49];
    unsigned char mode;
    unsigned short count;
    unsigned short saved;
    unsigned char pad_4e[8];
    unsigned short source;
} StreamRecord;

extern StreamRecord *D_80179924;
extern void func_8004B3E0(void);

void func_8004B8BC(void) {
    D_80179924->mode = 3;
    D_80179924->count = 0;
    D_80179924->saved = D_80179924->source;
    func_8004B3E0();
}
