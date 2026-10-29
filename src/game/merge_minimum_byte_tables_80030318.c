typedef struct ByteRow {
    unsigned char head[3];
    unsigned char pad3[5];
    unsigned char values[3];
    unsigned char padB[5];
} ByteRow;

void func_80030318(unsigned char *changed, ByteRow *destination,
                   ByteRow *source) {
    short i;
    short row;

    for (i = 0; i < 3; i++) {
        changed[i] = 1;
        if (source->head[i] < destination->head[i]) {
            destination->head[i] = source->head[i];
            changed[i] = 0;
        }
    }
    for (row = 0; row < 7; row++) {
        for (i = 0; i < 3; i++) {
            if (source[row].values[i] < destination[row].values[i]) {
                destination[row].values[i] = source[row].values[i];
                changed[i] = 0;
            }
        }
    }
}
