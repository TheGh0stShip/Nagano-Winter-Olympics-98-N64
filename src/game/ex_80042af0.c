typedef struct PackedData {
    unsigned char bytes[10][7];
    unsigned char nibbles[5];
    unsigned char packed[10][4];
    unsigned char extra[10][7];
    unsigned char padB9;
    unsigned short words[3];
} PackedData;

typedef struct UnpackedData {
    unsigned char bytes[10][9];
    unsigned char nibbles[10];
    unsigned char unpacked[10][8];
    unsigned char extra[10][7];
    unsigned short words[3];
} UnpackedData;

int func_80042AF0(UnpackedData *a, PackedData *b) {
    int result = 0;
    short i;
    short j;
    unsigned char high;

    for (i = 0; i < 3; i++) {
        if (a->words[i] != b->words[i]) {
            return 1;
        }
    }
    for (i = 0; i < 10; i++) {
        high = 0;
        for (j = 0; j < 7; j++) {
            if (a->bytes[i][j] != (b->bytes[i][j] & 0x7F)) {
                result = 1;
                break;
            }
            high += (b->bytes[i][j] & 0x80) >> (7 - j);
        }
        if (a->bytes[i][j] != high) {
            result = 1;
        }
        if (result) {
            break;
        }
        if (a->nibbles[i] != ((b->nibbles[i / 2] >> ((i % 2) * 4)) & 0xF)) {
            result = 1;
            break;
        }
        for (j = 0; j < 7; j++) {
            if (a->extra[i][j] != b->extra[i][j]) {
                result = 1;
                break;
            }
        }
        if (result) {
            break;
        }
        for (j = 0; j < 8; j++) {
            if (a->unpacked[i][j] != ((b->packed[i][j / 2] >> ((j % 2) * 4)) & 0xF)) {
                result = 1;
                break;
            }
        }
    }
    return result;
}
