typedef struct Matrix {
    signed int words[4][4];
} Matrix;

extern void func_80051E90(float matrix[4][4], unsigned int mode,
                          float first, float second, float third,
                          float fourth, float fifth);
extern void func_80052840(float matrix[4][4], Matrix *output);

void func_800520C0(Matrix *output, unsigned int mode,
                   float first, float second, float third,
                   float fourth, float fifth) {
    float matrix[4][4];

    func_80051E90(matrix, mode, first, second, third, fourth, fifth);
    func_80052840(matrix, output);
}
