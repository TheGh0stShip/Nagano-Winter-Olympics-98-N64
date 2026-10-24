typedef struct StreamRecord {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x31];
    unsigned short fallback;
    unsigned char pad3A[0x53];
    unsigned char progress;
    unsigned short value;
    unsigned short current;
    unsigned char duration;
} StreamRecord;

extern unsigned char D_80073B00[];
extern StreamRecord *D_80179924;

void func_8004C910(void) {
    D_80179924->current += D_80179924->duration;
    if (D_80179924->current >= 0x100) {
        D_80179924->current &= 0xFF;
        D_80179924->flags |= 2;
        D_80179924->fallback = D_80073B00[D_80179924->progress];
        D_80179924->progress++;
        D_80179924->progress &= 0x7F;
        D_80179924->fallback +=
            D_80073B00[D_80179924->progress] << 8;
        D_80179924->fallback &= D_80179924->value;
    }
}
