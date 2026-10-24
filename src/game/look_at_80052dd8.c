typedef struct Matrix {
    signed int words[4][4];
} Matrix;

extern void func_80052B20(float matrix[4][4],
                          float eye_x, float eye_y, float eye_z,
                          float at_x, float at_y, float at_z,
                          float up_x, float up_y, float up_z);
extern void func_80052840(float matrix[4][4], Matrix *output);

void func_80052DD8(Matrix *output,
                   float eye_x, float eye_y, float eye_z,
                   float at_x, float at_y, float at_z,
                   float up_x, float up_y, float up_z) {
    float matrix[4][4];

    func_80052B20(matrix, eye_x, eye_y, eye_z,
                  at_x, at_y, at_z, up_x, up_y, up_z);
    func_80052840(matrix, output);
}
