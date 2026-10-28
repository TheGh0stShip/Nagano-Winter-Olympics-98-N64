typedef struct StreamRecord {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x51];
    unsigned short value;
    unsigned char target;
    unsigned char steps;
    short delta;
} StreamRecord;

extern unsigned char *D_80179920;
extern StreamRecord *D_80179924;

void func_8004C2D4(void) {
    StreamRecord *record;
    int diff;

    D_80179924->steps = *D_80179920++;
    D_80179924->target = *D_80179920++;
    record = D_80179924;
    if (record->value < 0x8000) {
        if (record->flags & 4) {
            return;
        }
    }
    diff = (unsigned short)(record->target << 8) - (record->value & 0x7FFF);
    record->delta = diff / record->steps;
}
