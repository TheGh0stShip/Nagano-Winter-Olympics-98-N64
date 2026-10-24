typedef struct Matrix {
    signed int words[4][4];
} Matrix;

extern void func_8005AE70(float matrix[4][4], float first, float second,
                          float third, float fourth, float fifth,
                          float sixth, float seventh);
extern void func_80052840(float matrix[4][4], Matrix *output);

void func_8005B020(Matrix *output, float first, float second, float third,
                   float fourth, float fifth, float sixth, float seventh) {
    float matrix[4][4];

    func_8005AE70(matrix, first, second, third, fourth, fifth, sixth, seventh);
    func_80052840(matrix, output);
}
