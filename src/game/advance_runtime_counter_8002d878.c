typedef struct RuntimeState {
    unsigned short value;
} RuntimeState;

extern unsigned char *D_80126BF0;
extern unsigned char D_8013750F;
extern unsigned short D_80137510;
extern unsigned short D_80137512;

int func_8002D878(void) {
    RuntimeState *state = (RuntimeState *)(D_80126BF0 + 0x88338);

    state->value = 1;
    D_8013750F = 0xFF;
    D_80137510++;
    if (D_80137512 < D_80137510) {
        return 1;
    }
    return 0;
}
