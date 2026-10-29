void func_80003C10(unsigned char *dst, int count) {
    while (count--) {
        *dst++ = 0;
    }
}

void func_80003C38(unsigned char *src, unsigned char *dst, int count) {
    while (count--) {
        *dst++ = *src++;
    }
}

void func_80003C68(void) {
}

