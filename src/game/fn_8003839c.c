extern char D_8006F640[][10];

void func_8003839C(int index, long long value) {
    long long v = value;
    char *s;

    if (v < 0) {
        v = v * -1;
    }
    s = D_8006F640[index];
    *s++ = (v / 600000) % 6 + '0';
    *s++ = (v / 60000) % 10 + '0';
    *s++ = (v / 10000) % 6 + '0';
    *s++ = (v / 1000) % 10 + '0';
    *s++ = (v / 100) % 10 + '0';
    *s++ = (v / 10) % 10 + '0';
    *s = v % 10 + '0';
    s[1] = '+';
    s++;
    if (value < 0) {
        *s = '-';
    }
}
