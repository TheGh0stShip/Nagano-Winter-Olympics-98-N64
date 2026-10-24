typedef struct PositionedRecord {
    unsigned char pad_00[0x30];
    float x;
    float y;
    float z;
} PositionedRecord;

typedef struct PositionedLocals {
    unsigned char scratch[0x10];
    PositionedRecord record;
    unsigned char tail[4];
} PositionedLocals;

extern void func_80052940(PositionedRecord *record);
extern void func_80052840(PositionedRecord *record, int value);

void func_8005DD18(int value, float x, float y, float z) {
    PositionedLocals locals;

    func_80052940(&locals.record);
    locals.record.x = x;
    locals.record.y = y;
    locals.record.z = z;
    func_80052840(&locals.record, value);
}
