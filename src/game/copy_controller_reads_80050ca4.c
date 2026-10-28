typedef struct ContPad {
    unsigned short button;
    signed char stick_x;
    signed char stick_y;
    unsigned char errno;
    unsigned char pad5;
} ContPad;

typedef struct ContReadFormat {
    unsigned char dummy;
    unsigned char txsize;
    unsigned char rxsize;
    unsigned char cmd;
    unsigned short button;
    signed char stick_x;
    signed char stick_y;
} ContReadFormat;

extern unsigned char D_801929F0[];
extern unsigned char D_80192A31;

void func_80050CA4(ContPad *data) {
    unsigned char *ptr = D_801929F0;
    ContReadFormat readformat;
    int i;

    for (i = 0; i < D_80192A31; i++, ptr += sizeof(readformat), data++) {
        readformat = *(ContReadFormat *)ptr;
        data->errno = (readformat.rxsize & 0xC0) >> 4;
        if (data->errno == 0) {
            data->button = readformat.button;
            data->stick_x = readformat.stick_x;
            data->stick_y = readformat.stick_y;
        }
    }
}
