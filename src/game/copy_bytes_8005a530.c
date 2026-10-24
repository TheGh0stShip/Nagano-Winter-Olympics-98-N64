void *func_8005A530(void *destination, const void *source, unsigned int count) {
    unsigned char *output = destination;
    const unsigned char *input = source;

    for (; count != 0; output++, input++, count--) {
        *output = *input;
    }

    return destination;
}
