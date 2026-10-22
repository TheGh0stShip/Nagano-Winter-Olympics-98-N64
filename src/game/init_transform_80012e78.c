typedef struct TransformState {
    unsigned short state;
    unsigned char first;
    unsigned char second;
    float position[3];
    float rotation[3];
    float scale[3];
} TransformState;

void func_80012E78(TransformState *state) {
    state->state = 0;
    state->first = 0;
    state->second = 0;
    state->position[0] = 0.0f;
    state->position[1] = 0.0f;
    state->position[2] = 0.0f;
    state->rotation[0] = 0.0f;
    state->rotation[1] = 0.0f;
    state->rotation[2] = 0.0f;
    state->scale[0] = 1.0f;
    state->scale[1] = 1.0f;
    state->scale[2] = 1.0f;
}
