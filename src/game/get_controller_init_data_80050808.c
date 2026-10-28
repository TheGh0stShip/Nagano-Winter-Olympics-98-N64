typedef unsigned char u8;
typedef unsigned short u16;
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

typedef struct ControllerStatus {
    u16 type;
    u8 status;
    u8 error;
} ControllerStatus;

extern RequestFormat D_801929F0;
extern u8 D_80192A31;

void func_80050808(u8 *pattern, ControllerStatus *data) {
    u8 *ptr;
    RequestFormat format;
    s32 i;
    u8 bits = 0;

    ptr = (u8 *)&D_801929F0;
    for (i = 0; i < D_80192A31; i++, ptr += sizeof(format), data++) {
        format = *(RequestFormat *)ptr;
        data->error = (format.rxsize & 0xC0) >> 4;
        if (data->error == 0) {
            data->type = (format.typel << 8) | format.typeh;
            data->status = format.status;
            bits |= 1 << i;
        }
    }
    *pattern = bits;
}
