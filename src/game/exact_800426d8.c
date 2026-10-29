typedef struct PackedEntry {
    unsigned char data[7];
} PackedEntry;

typedef struct Packed {
    unsigned char head[2];
    unsigned char first[2];
    PackedEntry entries[16];
    unsigned char nibbles[8];
    unsigned char rows[15][2];
} Packed;

typedef struct UnpackedEntry {
    unsigned char data[7];
    unsigned char bits;
    unsigned char zero;
} UnpackedEntry;

typedef struct Unpacked {
    unsigned char head[2];
    unsigned char first[4];
    UnpackedEntry entries[16];
    unsigned char nibbles[16];
    unsigned char rows[15][2];
} Unpacked;

int func_800426D8(Unpacked *a, Packed *b) {
    short i;
    short j;
    unsigned char bits;
    int n;

    if (b->head[0] != a->head[0]) {
        return 1;
    }
    n = b->head[1];
    if (n != a->head[1]) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        if (a->first[i] != ((b->first[i / 2] >> ((i % 2) * 4)) & 0xF)) {
            return 1;
        }
    }
    for (i = 0; i < 16; i++) {
        bits = 0;
        for (j = 0; j < 7; j++) {
            if (a->entries[i].data[j] != (b->entries[i].data[j] & 0x7F)) {
                return 1;
            }
            bits += (b->entries[i].data[j] & 0x80) >> (7 - j);
        }
        if (bits != a->entries[i].bits) {
            return 1;
        }
    }
    for (i = 0; i < 16; i++) {
        if (a->nibbles[i] != ((b->nibbles[i / 2] >> ((i % 2) * 4)) & 0xF)) {
            return 1;
        }
    }
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 2; j++) {
            if (a->rows[i][j] != b->rows[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}
