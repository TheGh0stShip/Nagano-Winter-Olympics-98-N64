typedef struct HalfwordTarget {
    volatile short *value;
} HalfwordTarget;

void func_80038810(HalfwordTarget *target, int value) {
    if (target->value != 0) {
        *target->value = value;
    }
}
