typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct Matrix {
    s32 values[4][4];
} Matrix;

void func_800529F8(f32 destination[4][4], Matrix *source) {
    s32 i;
    s32 j;
    u32 first;
    u32 second;
    u32 *integer;
    u32 *fraction;
    s32 signedFirst;
    s32 signedSecond;

    integer = (u32 *)&source->values[0][0];
    fraction = (u32 *)&source->values[2][0];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            first = (*integer & 0xFFFF0000) | ((*fraction >> 16) & 0xFFFF);
            second = ((*(integer++) << 16) & 0xFFFF0000) |
                     (*(fraction++) & 0xFFFF);
            signedFirst = *(s32 *)&first;
            signedSecond = *(s32 *)&second;
            destination[i][j * 2] = (f32)signedFirst / 65536.0f;
            destination[i][j * 2 + 1] = (f32)signedSecond / 65536.0f;
        }
    }
}
