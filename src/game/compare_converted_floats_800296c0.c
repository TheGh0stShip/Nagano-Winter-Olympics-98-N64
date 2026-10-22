extern void func_80029274(int *, float);

int func_800296C0(float first, float second) {
    int first_value;
    int second_value;
    func_80029274(&first_value, first);
    func_80029274(&second_value, second);
    if (first_value == second_value) {
        return 1;
    }
    return 0;
}
