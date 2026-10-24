typedef struct Matrix {
    float values[4][4];
} Matrix;

void func_80059410(Matrix *matrix, float x, float y, float z,
                   float *output_x, float *output_y, float *output_z) {
    *output_x = matrix->values[0][0] * x + matrix->values[1][0] * y +
                matrix->values[2][0] * z + matrix->values[3][0];
    *output_y = matrix->values[0][1] * x + matrix->values[1][1] * y +
                matrix->values[2][1] * z + matrix->values[3][1];
    *output_z = matrix->values[0][2] * x + matrix->values[1][2] * y +
                matrix->values[2][2] * z + matrix->values[3][2];
}
