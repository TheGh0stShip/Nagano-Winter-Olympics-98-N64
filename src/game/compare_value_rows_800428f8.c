typedef struct Entry {
    unsigned char pad0[0x6E];
    unsigned short values[3];
} Entry;

typedef struct Table {
    unsigned char pad0[0x50];
    unsigned short rows[11][64];
    unsigned char pad5D0[0x70];
    unsigned short special[3];
} Table;

int func_800428F8(unsigned char kind, Entry *entry, Table *table) {
    short i;

    if (kind == 11) {
        for (i = 0; i < 3; i++) {
            if (entry->values[i] != table->special[i]) {
                return 1;
            }
        }
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (entry->values[i] != table->rows[kind][i]) {
            return 1;
        }
    }
    return 0;
}
