typedef struct Heap {
    unsigned char *base;
    unsigned char *cur;
    int len;
    int count;
} Heap;

void *func_8005F420(unsigned char *file, int line, Heap *hp, int num, int size) {
    int bytes;
    unsigned char *ptr = 0;

    bytes = (num * size + 15) & ~15;
    if ((hp->cur + bytes) <= (hp->base + hp->len)) {
        ptr = hp->cur;
        hp->cur += bytes;
    }
    return ptr;
}
