void *func_8005A530(void *destination, const void *source, unsigned int count) {
    unsigned char *output = destination;
    const unsigned char *input = source;

    for (; count != 0; output++, input++, count--) {
        *output = *input;
    }

    return destination;
}

int func_8005A55C(const unsigned char *text) {
    const unsigned char *cursor = text;
    while (*cursor != 0) {
        cursor++;
    }
    return cursor - text;
}

const char *func_8005A584(const char *s, int c) {
    const char ch = c;

    while (*s != ch) {
        if (*s == '\0') {
            return 0;
        }
        s++;
    }
    return s;
}
