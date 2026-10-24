typedef struct Matrix {
    signed int words[4][4];
} Matrix;

extern void func_8005BE10(float matrix[4][4], float first, float second,
                          float third, float fourth, float fifth,
                          float sixth, float seventh);
extern void func_80052840(float matrix[4][4], Matrix *output);

void func_8005BF64(Matrix *output, float first, float second, float third,
                   float fourth, float fifth, float sixth, float seventh) {
    float matrix[4][4];

    func_8005BE10(matrix, first, second, third, fourth, fifth, sixth, seventh);
    func_80052840(matrix, output);
}
