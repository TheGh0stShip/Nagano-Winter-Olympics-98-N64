typedef struct StreamRecord {
    unsigned char pad0[0x8A];
    unsigned short value;
    unsigned char enabled;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004CD60(void) {
    D_80179924->enabled = 1;
    D_80179924->value = *D_80179920;
    D_80179920++;
}
