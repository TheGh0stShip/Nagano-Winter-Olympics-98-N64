extern char *D_80126BF0;
void func_80025F60(float *source) {
    float *state = (float *)(D_80126BF0 + 0x7F898);
    state[4] = source[0];
    state[5] = source[1];
    state[11] = source[2];
}
