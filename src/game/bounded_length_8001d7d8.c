int func_8001D7D8(unsigned char *text) {
    int length;

    for (length = 0; length != 0x100; length++) {
        if (*text++ == 0) {
            break;
        }
    }
    return length;
}
