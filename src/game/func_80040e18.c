typedef struct Save {
    unsigned char data[0x7C4];
    unsigned int sum1;
    unsigned int sum2;
} Save;

extern Save *D_800730A8;

short func_80040E18(unsigned char slot) {
    unsigned char *base;
    unsigned int i;
    unsigned int sum;
    short ret;

    ret = 0;
    base = (unsigned char *)&D_800730A8[slot];
    sum = 0;
    for (i = 0; i < (unsigned int)((unsigned char *)&D_800730A8[slot].sum1 - (unsigned char *)&D_800730A8[slot]); i++) { sum += base[i]; }
    if (sum != D_800730A8[slot].sum1) {
        ret = 1;
    } else {
        sum = 0;
        for (i = 0; i < (unsigned int)((unsigned char *)&D_800730A8[slot].sum1 - (unsigned char *)&D_800730A8[slot]) >> 1; i++) { sum += base[i * 2]; }
        if (sum != D_800730A8[slot].sum2) {
            ret = 1;
        }
    }
    return ret;
}
