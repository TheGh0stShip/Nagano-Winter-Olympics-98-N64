int func_8005A55C(const unsigned char *text) {
    const unsigned char *cursor = text;
    while (*cursor != 0) {
        cursor++;
    }
    return cursor - text;
}
