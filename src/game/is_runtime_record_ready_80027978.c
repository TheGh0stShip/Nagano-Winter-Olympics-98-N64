typedef struct RuntimeRecord {
    unsigned char pad_000[0x13C];
    unsigned short state;
    unsigned short mode;
    unsigned short field_140;
    unsigned short pending;
} RuntimeRecord;

int func_80027978(RuntimeRecord *record) {
    if (record->state == 2 || record->mode == 3 || record->pending == 0) {
        return 1;
    }
    return 0;
}
