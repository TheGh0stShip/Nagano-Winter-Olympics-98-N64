extern void func_800090CC(short index, unsigned short value, int input);

void func_800060E8(short index, int input) {
    int original = index;

    func_800090CC((short)original, 3, input);
}
