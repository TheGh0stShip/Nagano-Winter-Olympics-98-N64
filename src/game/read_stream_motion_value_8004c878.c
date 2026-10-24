typedef struct StreamRecord {
    unsigned char pad0[0x38];
    unsigned short fallback;
    unsigned char pad3A[0x53];
    unsigned char progress;
    unsigned short value;
    unsigned short current;
    unsigned char duration;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004C878(void) {
    D_80179924->duration = *D_80179920;
    D_80179924->value = *++D_80179920 << 8;
    D_80179924->value += *++D_80179920;
    ++D_80179920;
    D_80179924->progress = 0;
    D_80179924->current = D_80179924->progress;
    if (D_80179924->duration == 0) {
        D_80179924->fallback = 0;
    }
}
