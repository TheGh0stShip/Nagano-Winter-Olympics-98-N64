typedef struct ByteBuffer {
    unsigned char *data;
    unsigned int size;
    unsigned int position;
} ByteBuffer;

void func_80003870(ByteBuffer *buffer, unsigned char *data, unsigned int size) {
    unsigned int i;

    i = 0;
    if (size != 0) {
        unsigned char *cursor;

        cursor = data;
        do {
            i++;
            *cursor++ = 0;
        } while (i < size);
    }
    buffer->data = data;
    buffer->size = size;
    buffer->position = 0;
}
