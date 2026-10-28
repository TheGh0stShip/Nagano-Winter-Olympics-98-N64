typedef struct RuntimeRecord {
    unsigned short kind;
    unsigned char pad2[0x146];
} RuntimeRecord;

extern unsigned char *D_80126BF0;
extern void func_80018704(RuntimeRecord *record, int id, int unused, float x, float y, float z);

void func_8001DB48(int id, float x, float y, int index) {
    RuntimeRecord *record = (RuntimeRecord *)(D_80126BF0 + 0x8B2C0) + index;

    if (record->kind < 2) {
        record->kind = 1;
    }
    func_80018704(record, id, 0, x, y, 0.0f);
}
