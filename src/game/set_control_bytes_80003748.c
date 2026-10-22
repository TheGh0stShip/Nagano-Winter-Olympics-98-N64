typedef struct ControlState {
    unsigned char pad[0x7C8E2];
    unsigned char value;
    unsigned char state;
} ControlState;

extern ControlState *D_80126BF0;

void func_80003748(unsigned char value) {
    D_80126BF0->value = value;
    D_80126BF0->state = 0;
}
