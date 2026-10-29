typedef struct PadSlot {
    unsigned short buttons;
    unsigned char pad2[12];
} PadSlot;

typedef struct Runtime {
    unsigned char pad0[0x7C8F8];
    PadSlot pads[4];
    unsigned char padFA[0x977EF - 0x7C8F8 - 4 * 14];
    unsigned char index;
    unsigned char count;
} Runtime;

extern Runtime *D_80126BF0;

unsigned short func_800474F4(int pad) {
    unsigned short buttons;
    int i;

    if (pad < 0 || pad >= 6) {
        return 0;
    }
    if (pad == 5) {
        buttons = 0;
        if (D_80126BF0->count < 0 || D_80126BF0->count >= 5) {
            D_80126BF0->count = 1;
        }
        for (i = 0; i < D_80126BF0->count; i++) {
            buttons |= D_80126BF0->pads[i].buttons;
        }
        return buttons;
    }
    if (pad == 4) {
        return D_80126BF0->pads[D_80126BF0->index].buttons;
    }
    return D_80126BF0->pads[pad].buttons;
}
