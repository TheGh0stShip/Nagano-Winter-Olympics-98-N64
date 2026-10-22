typedef struct RuntimeObject {
    unsigned char pad[0x28];
    float value;
} RuntimeObject;

extern unsigned char D_8013750E;

float func_8002D6B0(RuntimeObject *object) {
    if (object->value >= 1.2f) {
        return 0.0f;
    }
    if (object->value < 0.1f) {
        return 0.0f;
    }
    return D_8013750E * 0.0015f;
}
