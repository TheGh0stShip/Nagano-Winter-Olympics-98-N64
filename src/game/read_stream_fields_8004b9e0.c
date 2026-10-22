typedef struct StreamRecord {
    unsigned char pad0[0x18];
    unsigned short value;
    unsigned char pad1A[3];
    unsigned char flag;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004B9E0(void) {
    D_80179924->value = *D_80179920 << 8;
    D_80179920++;
    D_80179924->flag = 0;
}
