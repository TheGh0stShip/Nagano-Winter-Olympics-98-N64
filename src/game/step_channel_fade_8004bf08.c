typedef struct Channel {
    unsigned char pad0[6];
    unsigned char flags;
    unsigned char pad7[0x33];
    unsigned short volume;
    unsigned char pad3C[8];
    short delta;
    unsigned char level;
    unsigned char steps;
} Channel;

extern Channel *D_80179924;

void func_8004BF08(void) {
    int volume;

    D_80179924->flags |= 1;
    D_80179924->steps--;
    if (D_80179924->steps != 0) {
        volume = D_80179924->volume;
        volume += D_80179924->delta;
        if (volume < 0) {
            volume = 0;
        } else if (volume > 0xFF00) {
            volume = 0xFF00;
        }
        D_80179924->volume = volume;
    } else {
        D_80179924->volume = D_80179924->level << 8;
    }
}
