extern unsigned char D_801374B2;
extern void func_80029274(unsigned int *output, float value);

float func_8002932C(float value) {
    unsigned int converted;

    if (value <= 0.0f) {
        return value;
    }
    if ((double)(value < 0.0f ? -value : value) < 0.01) {
        return value;
    }
    if (D_801374B2 != 2) {
        if (D_801374B2 != 3) {
            return value;
        }
    }
    func_80029274(&converted, value);
    return (double)converted * 0.1;
}
