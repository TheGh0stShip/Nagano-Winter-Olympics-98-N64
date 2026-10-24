typedef struct RuntimeState {
    unsigned short value;
    unsigned char pad2[0x136];
} RuntimeState;

extern unsigned char *D_80126BF0;
extern unsigned char D_801374E8[];
extern unsigned short D_801374F0[];
extern unsigned short D_80137500[];

int func_8002CA88(index, channel)
unsigned short index;
unsigned char channel;
{
    RuntimeState *state;

    state = (RuntimeState *)(D_80126BF0 + 0x83EF8) + index;

    state->value = 1;
    D_801374E8[channel] = 0xFF;
    D_801374F0[channel]++;
    if (D_80137500[channel] < D_801374F0[channel]) {
        return 1;
    }
    return 0;
}
