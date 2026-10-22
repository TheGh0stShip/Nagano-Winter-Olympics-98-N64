typedef struct ToggleState {
    unsigned char pad00[0x30];
    unsigned short mode;
    unsigned char pad32[3];
    unsigned char value;
} ToggleState;

extern short D_80071F38;
extern void func_80030B30(unsigned char);

void func_80030B54(void) {
    ToggleState *state;
    if (state->mode == 1) {
        state->value = 255 - state->value;
        D_80071F38 = 255 - D_80071F38;
    }
    func_80030B30(3);
}
