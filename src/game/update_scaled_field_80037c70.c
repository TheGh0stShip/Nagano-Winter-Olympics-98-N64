typedef struct ScaledState {
    unsigned char padding[0x14];
    float value;
} ScaledState;

extern float func_8004E9D0(float value);

void func_80037C70(ScaledState *state, float input) {
    state->value = 170.0f - (func_8004E9D0(input) * 170.0f);
}
