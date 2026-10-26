typedef unsigned char (*FloatCallback)(float value);

extern FloatCallback D_80073220[];

unsigned char func_80046280(unsigned char index, float value) {
    unsigned char result = 0;

    if (index < 12 && D_80073220[index] != 0) {
        result = D_80073220[index](value);
    }
    if (result == 0) {
        result = 1;
    }
    return result;
}
