typedef struct Entry {
    unsigned short value;
    unsigned char pad2[12];
} Entry;

typedef struct Game {
    unsigned char pad0[0x7C8F6];
    Entry entries[6];
    unsigned char pad1[0x977EF - 0x7C8F6 - 6 * 14];
    char last;
    char count;
} Game;

extern Game *D_80126BF0;

unsigned short func_80047600(int id) {
    unsigned short result;
    int i;

    if (id < 0 || id >= 6) {
        return 0;
    }
    if (id == 5) {
        result = 0;
        if (D_80126BF0->count < 0 || D_80126BF0->count >= 5) {
            D_80126BF0->count = 1;
        }
        for (i = 0; i < D_80126BF0->count; i++) {
            result |= D_80126BF0->entries[i].value;
        }
        return result;
    }
    if (id == 4) {
        return D_80126BF0->entries[D_80126BF0->last].value;
    }
    return D_80126BF0->entries[id].value;
}
