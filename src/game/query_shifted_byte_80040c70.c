extern unsigned char *D_800730A8;
extern int func_80013E04(unsigned int first, void *context,
                         unsigned int shifted, unsigned int scale,
                         void *table);

int func_80040C70(unsigned char value, void *context) {
    signed short result = 0;

    if (func_80013E04(0, context, value << 11, 0x800,
                      D_800730A8 + 0x1F30) != 0) {
        result = 1;
    }
    return result;
}
