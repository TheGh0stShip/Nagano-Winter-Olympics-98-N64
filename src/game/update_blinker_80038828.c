typedef struct Blinker {
    unsigned short *output;
    unsigned char pad4[0xC];
    signed char count;
    signed char timer;
} Blinker;

extern unsigned char D_80137DF5;

void func_80038828(Blinker *blinker) {
    unsigned short *output = blinker->output;

    if (output == 0) {
        return;
    }
    *output = D_80137DF5;
    if (blinker->count == 0) {
        return;
    }
    if (blinker->timer++ >= 8) {
        *output = 1;
        blinker->timer = 0;
        blinker->count--;
        return;
    }
    if (blinker->timer == 4) {
        *output = 0;
    }
}
