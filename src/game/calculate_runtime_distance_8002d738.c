typedef struct RuntimeObject {
    unsigned char pad_00[0x0C];
    float x;
    unsigned char pad_10[4];
    float z;
} RuntimeObject;

extern unsigned char D_8013750E;
extern float sqrtf(float);
#pragma intrinsic(sqrtf)

float func_8002D738(RuntimeObject *object) {
    return (sqrtf(object->x * object->x + object->z * object->z) + 10.0f) *
           D_8013750E * 0.01;
}
