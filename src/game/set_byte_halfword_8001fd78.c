typedef unsigned char u8;
typedef short s16;
void func_8001FD78(u8 *object, u8 byte_value, s16 halfword_value) {
    object[0x125] = byte_value;
    *(s16 *)(object + 0x126) = halfword_value;
}
