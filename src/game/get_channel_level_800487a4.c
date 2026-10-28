typedef struct Channel {
    unsigned char pad0[0xB0];
    unsigned char level[3];
    signed char base[3];
} Channel;

typedef struct Preset {
    short value;
    short pad[2];
} Preset;

extern Channel *D_80179924;
extern Preset D_801796A2[];

int func_800487A4(unsigned char preset, unsigned char index) {
    int base;

    if (D_80179924->level[index] != 0) {
        if (index == 0) {
            base = D_80179924->base[index] << 8;
        } else {
            base = D_80179924->base[index];
        }
        base += D_801796A2[preset].value * D_80179924->level[index] / 10;
        return base;
    }
    return D_801796A2[preset].value;
}
