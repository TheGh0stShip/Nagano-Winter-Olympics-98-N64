typedef struct Channel {
    unsigned char pad0[0x18];
    unsigned short volume;
    unsigned char pad1A[2];
    unsigned char level;
    unsigned char steps;
    short delta;
} Channel;

extern Channel *D_80179924;

void func_8004BAB8(void) {
    int volume;

    D_80179924->steps--;
    if (D_80179924->steps != 0) {
        volume = D_80179924->volume;
        volume += D_80179924->delta;
        if (volume < 0x100) {
            volume = 0x100;
        } else if (volume > 0xFF00) {
            volume = 0xFF00;
        }
        D_80179924->volume = volume;
    } else {
        D_80179924->volume = D_80179924->level << 8;
    }
}
