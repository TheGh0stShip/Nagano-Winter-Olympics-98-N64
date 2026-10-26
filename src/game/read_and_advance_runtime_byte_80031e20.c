extern unsigned char *D_80126BF0;
extern unsigned short D_801376C0;

typedef struct RuntimeBytes {
    unsigned char pad[0x92C78];
    unsigned char values[];
} RuntimeBytes;

unsigned char func_80031E20(unsigned char direction) {
    unsigned char value =
        ((RuntimeBytes *)D_80126BF0)->values[D_801376C0];

    if (direction == 1) {
        D_801376C0++;
    }
    if (direction == 2) {
        D_801376C0--;
    }
    return value;
}
