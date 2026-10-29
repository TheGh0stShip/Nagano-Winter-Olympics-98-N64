typedef struct Entry {
    unsigned short state;
    unsigned short id;
    unsigned char pad4[4];
    float x;
    float y;
    float z;
    unsigned char pad14[0x13E];
    unsigned char mode;
    unsigned char pad153[0x2D5];
} Entry;

typedef struct Point {
    unsigned char pad0[4];
    float x;
    float y;
    float z;
} Point;

typedef struct FlagRecord {
    unsigned char pad[0x3C];
} FlagRecord;

typedef struct Game {
    unsigned char pad[0x7D23C];
    FlagRecord records[1];
} Game;

extern Game *D_80126BF0;
extern void func_8001FF8C(Entry *entry);
extern void func_80009414(void *record, Entry *entry);

void func_80016A6C(Entry *entry, Point *origin, short id, short *count) {
    short i;
    float dx;
    float dy;
    float dz;
    float x;
    float y;
    float z;

    for (i = 0; i < 10; i++, entry++) {
        if (entry->state >= 2) {
            if (id == 0) {
                entry->state--;
            }
        } else if (id == entry->id) {
            if (entry->mode == 1 || entry->state != 0) {
                dx = entry->x - origin->x;
                if (dx < -10000.0f || 10000.0f < dx) {
                    continue;
                }
                dy = entry->y - origin->y;
                if (dy < -10000.0f || 10000.0f < dy) {
                    continue;
                }
                dz = entry->z - origin->z;
                if (dz < -10000.0f || 10000.0f < dz) {
                    continue;
                }
                func_8001FF8C(entry);
                x = entry->x;
                y = entry->y;
                z = entry->z;
                entry->x = dx;
                entry->y = dy;
                entry->z = dz;
                if (entry->mode != 1 || entry->state != 0) {
                    func_80009414(&D_80126BF0->records[*count], entry);
                    (*count)++;
                    entry->x = x;
                    entry->y = y;
                    entry->z = z;
                }
            }
        }
    }
}
