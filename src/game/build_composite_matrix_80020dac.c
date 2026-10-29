typedef float MatrixF[4][4];

extern void func_80020BF0(MatrixF, float, float, float, float, float, float,
                          float, float, float);
extern void func_800594B0(MatrixF, MatrixF, MatrixF);
extern void func_80052840(MatrixF, void *);

void func_80020DAC(void *output, float x, float y, float z, float rx, float ry,
                   float rz, float sx, float sy, float sz, float tx, float ty,
                   float tz) {
    MatrixF first;
    MatrixF second;
    MatrixF result;

    func_80020BF0(first, x, y, z, rx, ry, rz, sx, sy, sz);
    func_80020BF0(second, tx, ty, tz, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                  1.0f);
    func_800594B0(second, first, result);
    func_80052840(result, output);
}
