typedef struct Slot {
    unsigned char low[7];
    unsigned char high;
    unsigned char zero;
} Slot;

typedef struct Pair {
    unsigned char v[2];
} Pair;

typedef struct Packed {
    unsigned char kind;
    unsigned char count;
    unsigned char nibbles[4];
    Slot slots[16];
    unsigned char levels[16];
    Pair extra[15];
} Packed;

extern void func_8000F360(void *);

void func_80041D10(unsigned char *record) {
    Packed buf;
    short i;
    short j;
    unsigned char bits;

    buf.kind = record[0];
    buf.count = record[1];
    for (i = 0; i < 4; i++) {
        if (i < record[1]) {
            buf.nibbles[i] = (*(record + 2 + i / 2) >> (i % 2 * 4)) & 0xF;
        } else {
            buf.nibbles[i] = 0;
        }
    }
    for (i = 0; i < 16; i++) {
        bits = 0;
        for (j = 0; j < 7; j++) {
            buf.slots[i].low[j] = *(record + 4 + i * 7 + j) & 0x7F;
            bits |= (*(record + 4 + i * 7 + j) & 0x80) >> (7 - j);
        }
        buf.slots[i].high = bits;
        buf.slots[i].zero = 0;
    }
    for (i = 0; i < 16; i++) {
        buf.levels[i] = (*(record + 0x74 + i / 2) >> (i % 2 * 4)) & 0xF;
    }
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 2; j++) {
            buf.extra[i].v[j] = ((Pair *)(record + 0x7C))[i].v[j];
        }
    }
    func_8000F360(&buf);
}
