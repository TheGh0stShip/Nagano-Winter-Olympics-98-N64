typedef struct ControlState {
    unsigned char pad[0x7C8F0];
    unsigned char state;
    unsigned char active;
    unsigned char next;
} ControlState;

extern ControlState *D_80126BF0;
extern void func_800127A4(void);

void func_800127BC(void) {
    func_800127A4();
    D_80126BF0->next = 0;
    D_80126BF0->state = D_80126BF0->next;
}
