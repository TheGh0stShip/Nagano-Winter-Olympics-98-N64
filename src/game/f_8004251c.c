typedef unsigned char u8;

typedef struct Packed {
    u8 header[2];
    u8 rows[16][7];
    u8 nibbles[8];
    u8 tail[16][6];
} Packed;

typedef struct Expanded {
    u8 header[2];
    u8 rows[16][9];
    u8 nibbles[16];
    u8 tail[16][7];
} Expanded;

int func_8004251C(Expanded *a, Packed *b) {
    short i;
    short j;
    u8 bits;

    if (b->header[0] != a->header[0]) {
        return 1;
    }
    if (b->header[1] != a->header[1]) {
        return 1;
    }
    for (i = 0; i < 16; i++) {
        bits = 0;
        for (j = 0; j < 7; j++) {
            if (a->rows[i][j] != (b->rows[i][j] & 0x7F)) {
                return 1;
            }
            bits += (b->rows[i][j] & 0x80) >> (7 - j);
        }
        if (bits != a->rows[i][7]) {
            return 1;
        }
    }
    for (i = 0; i < 16; i++) {
        if (a->nibbles[i] != ((b->nibbles[i / 2] >> ((i % 2) * 4)) & 0xF)) {
            return 1;
        }
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 6; j++) {
            if (a->tail[i][j] != b->tail[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}
