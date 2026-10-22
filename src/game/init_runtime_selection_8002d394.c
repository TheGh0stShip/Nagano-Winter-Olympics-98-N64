typedef struct RuntimeState {
    unsigned short value;
    unsigned short enabled;
    unsigned char pad[0x124];
    unsigned int selection;
} RuntimeState;

extern unsigned char *D_80126BF0;
extern unsigned int D_80071D1C[];

void func_8002D394(void) {
    RuntimeState *state = (RuntimeState *)(D_80126BF0 + 0x88338);

    state->enabled = 1;
    state->selection = D_80071D1C[D_80126BF0[0x977EC]];
    state->value = 0;
}
