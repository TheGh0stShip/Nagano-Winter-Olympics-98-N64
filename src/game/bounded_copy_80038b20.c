void func_80038B20(unsigned char *destination, unsigned char *source, int count) {
    int i;

    for (i = 0; i < count; i++) {
        unsigned char value = *source++;
        if (value == 0) {
            break;
        }
        *destination++ = value;
    }
    *destination = 0;
}
