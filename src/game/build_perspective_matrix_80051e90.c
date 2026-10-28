typedef unsigned short u16;
extern void func_80052940(float mf[4][4]);
extern float func_8005C4E0(float value);
extern float func_8004E9D0(float value);

void func_80051E90(float mf[4][4], u16 *perspNorm, float fovy, float aspect,
                   float near, float far, float scale) {
    float cot;
    int i;
    int j;

    func_80052940(mf);
    fovy *= 3.1415926 / 180.0;
    cot = func_8005C4E0(fovy / 2) / func_8004E9D0(fovy / 2);
    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = -1;
    mf[3][2] = (2 * near * far) / (near - far);
    mf[3][3] = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            mf[i][j] *= scale;
    if (perspNorm != (u16 *)0) {
        if (near + far <= 2.0) {
            *perspNorm = (u16)0xFFFF;
        } else {
            *perspNorm = (u16)((2.0 * 65536.0) / (near + far));
            if (*perspNorm <= 0)
                *perspNorm = (u16)0x0001;
        }
    }
}
