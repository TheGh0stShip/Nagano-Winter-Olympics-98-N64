typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

u8 func_8005E1E0(u16 address) {
    u8 crc = 0;
    u8 feedback;
    s32 i;

    for (i = 0; i < 16; i++) {
        feedback = (crc & 0x10) ? 0x15 : 0;
        crc <<= 1;
        crc |= (u8)((address & 0x400) ? 1 : 0);
        address <<= 1;
        crc ^= feedback;
    }
    return crc & 0x1F;
}
