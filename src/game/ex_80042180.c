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

extern void func_8000F310(UnpackedData *data);

void func_80042180(PackedData *src) {
    UnpackedData out;
    short i;
    short j;
    unsigned char high;

    for (i = 0; i < 10; i++) {
        high = 0;
        for (j = 0; j < 7; j++) {
            out.bytes[i][j] = src->bytes[i][j] & 0x7F;
            high |= (src->bytes[i][j] & 0x80) >> (7 - j);
        }
        out.bytes[i][7] = high;
        out.bytes[i][8] = 0;
        out.nibbles[i] = (src->nibbles[i / 2] >> ((i % 2) * 4)) & 0xF;
        for (j = 0; j < 7; j++) {
            out.extra[i][j] = src->extra[i][j];
        }
        for (j = 0; j < 8; j++) {
            out.unpacked[i][j] = (src->packed[i][j / 2] >> ((j % 2) * 4)) & 0xF;
        }
    }
    for (i = 0; i < 3; i++) {
        out.words[i] = src->words[i];
    }
    func_8000F310(&out);
}
