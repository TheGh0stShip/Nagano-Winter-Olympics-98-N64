typedef struct ControlState {
    unsigned char pad[0x7C8E0];
    unsigned char value;
    unsigned char state;
} ControlState;

extern ControlState *D_80126BF0;
extern void func_80003748(int);

void func_80003778(unsigned char value) {
    D_80126BF0->value = value;
    D_80126BF0->state = 0;
    func_80003748(0);
}
