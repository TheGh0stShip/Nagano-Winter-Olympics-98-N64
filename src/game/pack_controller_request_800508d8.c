typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct RequestFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 command;
    u8 typeh;
    u8 typel;
    u8 status;
    u8 dummy1;
} RequestFormat;

typedef struct PifRam {
    u32 ram[15];
    u32 status;
} PifRam;

extern PifRam D_801929F0;
extern u8 D_80192A31;

void func_800508D8(u8 command) {
    u8 *ptr;
    RequestFormat format;
    s32 i;

    for (i = 0; i < 16; i++) {
        ((u32 *)&D_801929F0)[i] = 0;
    }
    D_801929F0.status = 1;
    ptr = (u8 *)&D_801929F0;
    format.dummy = 0xFF;
    format.txsize = 1;
    format.rxsize = 3;
    format.command = command;
    format.typeh = 0xFF;
    format.typel = 0xFF;
    format.status = 0xFF;
    format.dummy1 = 0xFF;
    for (i = 0; i < D_80192A31; i++) {
        *(RequestFormat *)ptr = format;
        ptr += sizeof(format);
    }
    *ptr = 0xFE;
}
