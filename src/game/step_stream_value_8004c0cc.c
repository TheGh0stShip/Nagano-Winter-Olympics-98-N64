typedef struct StreamRecord {
    unsigned char pad0[0x22];
    unsigned char held;
    unsigned char pad23[0x26];
    unsigned char mode;
    unsigned char pad4A[2];
    unsigned short saved;
    unsigned char pad4E[8];
    unsigned short pitch;
} StreamRecord;

typedef struct PitchEntry {
    unsigned short pad0;
    unsigned short value;
    unsigned short pad4[2];
} PitchEntry;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;
extern PitchEntry D_80073AD8[];
void func_8004C0CC(void) {
    D_80179924->pitch = D_80073AD8[0 - (*D_80179920 & 0xFF)].value;
    D_80179920++;
    if (D_80179924->held == 0 && D_80179924->mode == 3) {
        D_80179924->saved = D_80179924->pitch;
    }
}
