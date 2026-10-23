extern float func_8002970C(void);

void func_80029274(unsigned int *output, float value) {
    float scale = func_8002970C();

    *output = (unsigned int)(value * scale);
}
