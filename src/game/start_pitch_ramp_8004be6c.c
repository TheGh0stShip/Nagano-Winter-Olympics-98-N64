typedef struct StreamRecord {
    unsigned char pad0[0x3A];
    unsigned short volume;
    unsigned char pad3C[8];
    short delta;
    unsigned char target;
    unsigned char steps;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;
void func_8004BE6C(void) {
    StreamRecord *record;
    int diff;

    D_80179924->steps = *D_80179920++;
    D_80179924->target = *D_80179920++;
    record = D_80179924;
    diff = (unsigned short)(record->target << 8) - record->volume;
    record->delta = diff / record->steps;
}
