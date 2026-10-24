typedef struct BufferRecord {
    void *start;
    void *current;
    unsigned int field_08;
    unsigned int field_0C;
    unsigned int limit;
    unsigned int value;
} BufferRecord;

extern unsigned char D_8007C940[];

void func_8005A5D0(BufferRecord *record, unsigned int value,
                   unsigned int limit) {
    record->start = D_8007C940;
    record->current = D_8007C940;
    record->field_08 = 0;
    record->field_0C = 0;
    record->limit = limit;
    record->value = value;
}
