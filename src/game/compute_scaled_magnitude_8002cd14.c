extern unsigned char D_801374E0[];

float func_8002CD14(float value, unsigned char index) {
    float count;
    float magnitude;

    count = (unsigned int)D_801374E0[index];
    magnitude = value < 0.0f ? -value : value;
    return (magnitude + 20.0f) * count * 0.01;
}
