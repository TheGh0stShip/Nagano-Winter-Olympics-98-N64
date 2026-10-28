void func_8005BD30(unsigned char *src, unsigned char *dst, int size) {
    unsigned char *s = src;
    unsigned char *d = dst;
    int i;

    for (i = 0; i < size; i++) {
        *d++ = *s++;
    }
}
