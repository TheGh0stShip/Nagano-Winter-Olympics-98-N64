typedef struct Save {
    unsigned char data[0x7C4];
    unsigned int sum1;
    unsigned int sum2;
} Save;

extern Save *D_800730A8;
extern int func_80040A80(unsigned char slot, int arg1);

int func_80040CC4(unsigned char slot, int arg1) {
    unsigned char *base;
    unsigned int i;
    unsigned int sum;
    unsigned int sum2;

    base = (unsigned char *)&D_800730A8[slot];
    for (i = 0; i < sizeof(Save); i++) { base[i] = 0; }
    sum = 0;
    for (i = 0; i < (unsigned int)((unsigned char *)&D_800730A8[slot].sum1 - (unsigned char *)&D_800730A8[slot]); i++) { sum += base[i]; }
    D_800730A8[slot].sum1 = sum;
    sum = 0;
    for (i = 0; i < (unsigned int)((unsigned char *)&D_800730A8[slot].sum1 - (unsigned char *)&D_800730A8[slot]) >> 1; i++) { sum += base[i * 2]; }
    D_800730A8[slot].sum2 = sum;
    return func_80040A80(slot, arg1);
}
