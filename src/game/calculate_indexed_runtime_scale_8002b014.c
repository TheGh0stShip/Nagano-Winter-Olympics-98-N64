typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_80126BF0;
extern u8 D_8006D47A[][24][14];
extern float D_8006E470[][2];
extern int func_80027CC0(u16 value);

float func_8002B014(u16 index, u8 mode) {
    int value;
    float result;

    value = func_80027CC0((*(u16 *)(D_80126BF0 + 0x7C8D8) + index * 10) &
                         0x7FFF);
    result = D_8006D47A[mode][index][0];
    result *= (float)(value & 0xFFF) / 2048 - 1.0f;
    result *= D_8006E470[mode][0];
    return result;
}
