typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
extern s32 D_8007C998;

s32 func_8005B820(u32 frequency) {
    register u32 dacRate;
    register u8 bitRate;
    register float value;

    value = D_8007C998 / (float)frequency + 0.5f;
    dacRate = value;
    if (dacRate < 132) {
        return -1;
    }
    bitRate = dacRate / 66;
    if (bitRate > 16) {
        bitRate = 16;
    }
    *(volatile u32 *)0xA4500010 = dacRate - 1;
    *(volatile u32 *)0xA4500014 = bitRate - 1;
    *(volatile u32 *)0xA4500008 = 1;
    return D_8007C998 / (s32)dacRate;
}
