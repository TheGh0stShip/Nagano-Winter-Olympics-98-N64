typedef struct Entry {
    unsigned short state;
    unsigned short id;
    unsigned char pad[0x144];
} Entry;

typedef struct FlagRecord {
    unsigned char pad[0x3C];
} FlagRecord;

typedef struct Game {
    unsigned char pad[0x7D23C];
    FlagRecord records[1];
} Game;

extern Game *D_80126BF0;
extern void func_8001B008(Entry *entry);
extern void func_80009630(void *record, Entry *entry);

void func_80016974(Entry *entry, int unused, short id, short *count) {
    short i;

    for (i = 0; i < 2; i++, entry++) {
        if (entry->state != 0) {
            if (entry->state >= 2) {
                if (id == 0) {
                    entry->state--;
                }
            } else if (id == entry->id) {
                func_8001B008(entry);
                func_80009630(&D_80126BF0->records[*count], entry);
                (*count)++;
            }
        }
    }
}
