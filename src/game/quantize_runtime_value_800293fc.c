extern unsigned char *D_80126BF0;

float func_800293FC(float x, float y) {
    float value;
    unsigned int quantized;

    if (D_80126BF0[0x977EC] == 2) {
        value = (x - 90.0f) * 2.0f + y + 60.0f;
    } else {
        value = (x - 120.0f) * 1.8f + y + 60.0f;
    }
    if (value < 10.0f) {
        return value;
    }
    quantized = (unsigned int)(value * 10.0f);
    value = (float)(quantized - quantized % 5);
    value *= 0.1;
    return value;
}
