typedef unsigned char u8;

typedef struct Runtime22C28 {
    u8 pad00[8];
    float radius;
    float sourceX;
    float sourceZ;
    float sourceY;
    float outputX;
    float outputZ;
    float outputY;
    float targetX;
    float targetZ;
    float targetY;
    u8 pad30[0x28];
    u8 complete;
} Runtime22C28;

extern float sqrtf(float value);
#pragma intrinsic(sqrtf)
extern void func_80022E64(Runtime22C28 *record);

void func_80022C28(Runtime22C28 *record) {
    long long pad0;
    long long pad1;
    long long pad2;
    long long pad3;
    int pad4;
    float dx = record->targetX - record->sourceX;
    float dz = record->targetZ - record->sourceZ;
    float dy = record->targetY - record->sourceY;
    float distance = sqrtf(dx * dx + dz * dz + dy * dy);

    if (distance < record->radius) {
        record->complete = 1;
    } else {
        record->outputX = record->sourceX + (float)((double)dx * 0.05);
        record->outputZ = record->sourceZ + (float)((double)dz * 0.05);
        record->outputY = record->sourceY + (float)((double)dy * 0.05);
        func_80022E64(record);
    }
}
