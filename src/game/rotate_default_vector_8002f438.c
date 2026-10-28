extern float D_80137534;
extern void func_8004E7E0(float mf[4][4], float a, float x, float y, float z);
extern void func_80059410(float mf[4][4], float x, float y, float z, float *ox, float *oy, float *oz);

void func_8002F438(float x, float y, float z, float *outX, float *outY, float *outZ) {
    float unused;
    float mf[4][4];
    float out[3];

    func_8004E7E0(mf, D_80137534, 0.0f, 1.0f, 0.0f);
    func_80059410(mf, x, y, z, &out[0], &out[1], &out[2]);
    *outX = out[0];
    *outY = out[1];
    *outZ = out[2];
}
