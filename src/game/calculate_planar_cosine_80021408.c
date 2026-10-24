typedef struct Vector {
    float x;
    float y;
    float z;
} Vector;

extern float sqrtf(float value);
#pragma intrinsic(sqrtf)

float func_80021408(Vector *first, Vector *second) {
    float dot = second->z * first->z + first->x * second->x;
    float first_length = sqrtf(first->z * first->z + first->x * first->x);
    float second_length =
        sqrtf(second->z * second->z + second->x * second->x);

    if (first_length == 0.0f || second_length == 0.0f) {
        return 1.0f;
    }
    return dot / (first_length * second_length);
}
