extern signed char D_80138220[];
extern void func_800404EC(signed char output[4]);

void func_8003F9E0(void) {
    signed short index;
    signed char output[4];

    func_800404EC(output);
    for (index = 0; index < 4; index++) {
        D_80138220[index * 2] = output[index];
    }
}
