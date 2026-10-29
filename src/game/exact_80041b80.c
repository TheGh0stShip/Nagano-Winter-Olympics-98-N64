typedef struct InEntry {
    unsigned char data[7];
} InEntry;

typedef struct InRow {
    unsigned char data[6];
} InRow;

typedef struct Input {
    unsigned char head[2];
    InEntry entries[16];
    unsigned char nibbles[8];
    InRow rows[16];
} Input;

typedef struct OutEntry {
    unsigned char data[7];
    unsigned char bits;
    unsigned char zero;
} OutEntry;

typedef struct OutRow {
    unsigned char data[7];
} OutRow;

typedef struct Output {
    unsigned char head[2];
    OutEntry entries[16];
    unsigned char nibbles[16];
    OutRow rows[16];
} Output;

extern void func_8000EDB8(Output *out);

void func_80041B80(Input *src) {
    Output out;
    short i;
    short j;
    unsigned char bits;

    out.head[0] = src->head[0];
    out.head[1] = src->head[1];
    for (i = 0; i < 16; i++) {
        bits = 0;
        for (j = 0; j < 7; j++) {
            out.entries[i].data[j] = src->entries[i].data[j] & 0x7F;
            bits |= (src->entries[i].data[j] & 0x80) >> (7 - j);
        }
        out.entries[i].bits = bits;
        out.entries[i].zero = 0;
    }
    for (i = 0; i < 16; i++) {
        out.nibbles[i] = (src->nibbles[i / 2] >> ((i % 2) * 4)) & 0xF;
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 6; j++) {
            out.rows[i].data[j] = src->rows[i].data[j];
        }
    }
    func_8000EDB8(&out);
}
