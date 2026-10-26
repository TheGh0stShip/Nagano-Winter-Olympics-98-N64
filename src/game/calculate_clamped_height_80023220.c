typedef struct HeightState {
    unsigned char pad[0x58];
    float height;
} HeightState;

float func_80023220(HeightState *state) {
    float result = (float)((double)state->height * 0.5);

    result += 60.0f;

    if (result > 85.0f) {
        result = 85.0f;
    }
    return result;
}
