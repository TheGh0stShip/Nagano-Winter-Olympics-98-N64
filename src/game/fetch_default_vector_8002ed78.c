extern void func_8002F438(float x, float y, float z, float *outX, float *outY, float *outZ);

void func_8002ED78(float *out) {
    unsigned short i;
    float values[3];

    func_8002F438(0.0f, 0.0f, 100.0f, &values[0], &values[1], &values[2]);
    for (i = 0; i < 3; i++) out[i] = values[i];
}
