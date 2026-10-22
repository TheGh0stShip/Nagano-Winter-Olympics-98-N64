typedef struct WordBuffer {
    unsigned char pad0[0x14];
    int count;
    unsigned char pad1[4];
    int *words;
} WordBuffer;

int func_80056FE0(WordBuffer *buffer, int type, int value) {
    int *words = buffer->words;
    if (type == 2) {
        words[buffer->count] = value;
        buffer->count++;
    }
    return 0;
}
