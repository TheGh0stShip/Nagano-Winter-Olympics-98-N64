typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Position {
    u8 pad00[0xC];
    float x;
    u8 pad10[4];
    float z;
} Position;

extern float sqrtf(float);
#pragma intrinsic(sqrtf)

int func_8002D5AC(Position *position) {
    u8 value = (u32)(sqrtf(position->x * position->x +
                           position->z * position->z) / 300.0f * 256.0f);

    return (u8)(255 - value);
}
