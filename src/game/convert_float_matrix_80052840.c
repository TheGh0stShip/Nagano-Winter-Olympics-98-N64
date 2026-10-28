typedef int s32;
typedef float f32;
typedef struct Mtx { s32 m[4][4]; } Mtx;

#define FTOFIX32(value) ((s32)((value) * (f32)0x10000))

void func_80052840(f32 source[4][4], Mtx *destination) {
    s32 i;
    s32 j;
    s32 first;
    s32 second;
    s32 *integer;
    s32 *fraction;

    integer = &destination->m[0][0];
    fraction = &destination->m[2][0];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            first = FTOFIX32(source[i][j * 2]);
            second = FTOFIX32(source[i][j * 2 + 1]);
            *integer++ = (first & 0xFFFF0000) | ((second >> 16) & 0xFFFF);
            *fraction++ = ((first << 16) & 0xFFFF0000) | (second & 0xFFFF);
        }
    }
}
