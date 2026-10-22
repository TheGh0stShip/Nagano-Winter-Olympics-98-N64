typedef struct IndexedRecord {
    int unused;
    int value;
} IndexedRecord;

extern IndexedRecord *D_8006C140[];

int func_80039544(int index) {
    IndexedRecord *record = D_8006C140[index];
    return record->value;
}
