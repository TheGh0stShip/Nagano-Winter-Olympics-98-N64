typedef struct AlignedBuffer {
    unsigned int start;
    unsigned int current;
    unsigned int size;
    unsigned int field_0C;
} AlignedBuffer;

void func_8005A3F0(AlignedBuffer *buffer, unsigned int start,
                   unsigned int size) {
    unsigned int adjustment = 0x10 - (start & 0xF);

    if (adjustment != 0x10) {
        buffer->start = start + adjustment;
    } else {
        buffer->start = start;
    }
    buffer->current = buffer->start;
    buffer->size = size;
    buffer->field_0C = 0;
}
