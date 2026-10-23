typedef struct StreamRecord {
    unsigned char pad0[0x88];
    unsigned char first;
    unsigned char second;
    short value;
    unsigned char enabled;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004CC64(void) {
    D_80179924->enabled = 0;
    D_80179924->first = *D_80179920;
    D_80179920++;
    D_80179924->second = *D_80179920;
    D_80179920++;
    D_80179924->value = *(signed char *)D_80179920 << 8;
    D_80179920++;
}
