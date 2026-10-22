typedef struct RuntimeState {
    unsigned char pad_00[0x0C];
    float zero;
    unsigned char pad_10[4];
    float negative_limit;
    unsigned char pad_18[0x0C];
    float first;
    float second;
    float third;
} RuntimeState;

extern unsigned char *D_80126BF0;

void func_8002D79C(void) {
    RuntimeState *state = (RuntimeState *)(D_80126BF0 + 0x88338);

    state->first = 1.2f;
    state->second = 0.2f;
    state->zero = 0.0f;
    state->negative_limit = -300.0f;
    state->third = 1.2f;
}
