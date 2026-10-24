typedef struct StreamState {
    unsigned char pad[0x49];
    unsigned char mode;
} StreamState;

extern StreamState *D_80179924;

int func_8004B384(int value, unsigned char scale, unsigned char alternate) {
    if (D_80179924->mode >= 2) {
        if (value < 0x200) {
            value = (scale * value) >> 8;
        } else {
            value = (scale * alternate) << 1;
        }
    }
    return value;
}
