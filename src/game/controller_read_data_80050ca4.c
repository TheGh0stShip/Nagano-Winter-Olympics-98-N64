typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct ContPad {
    u16 button;
    signed char stick_x;
    signed char stick_y;
    u8 errno;
    u8 pad5;
} ContPad;

typedef struct ContReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 button;
    signed char stick_x;
    signed char stick_y;
} ContReadFormat;

typedef struct RequestFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 command;
    u16 type;
    signed char status;
    signed char dummy1;
} RequestFormat;

typedef struct PifRam {
    u32 ram[15];
    u32 status;
} PifRam;

extern PifRam D_801929F0;
extern u8 D_80192A31;

void func_80050CA4(ContPad *data) {
    u8 *ptr = (u8 *)&D_801929F0;
    ContReadFormat readformat;
    s32 i;

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

void func_80050D4C(void) {
    u8 *ptr;
    RequestFormat format;
    s32 i;

    ptr = (u8 *)&D_801929F0;
    for (i = 0; i < 16; i++) {
        ((u32 *)&D_801929F0)[i] = 0;
    }
    D_801929F0.status = 1;
    format.dummy = 0xFF;
    format.txsize = 1;
    format.rxsize = 4;
    format.command = 1;
    format.type = 0xFFFF;
    format.status = -1;
    format.dummy1 = -1;
    for (i = 0; i < D_80192A31; i++) {
        *(RequestFormat *)ptr = format;
        ptr += sizeof(format);
    }
    *ptr = 0xFE;
}
