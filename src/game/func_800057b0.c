extern float func_8004E9D0(float value);
extern float func_8005C4E0(float value);

void func_800057B0(int *m, float x, float y, float z, float rx, float ry,
                   float rz, float sx, float sy, float sz) {
    static float degreesToRadians = 3.1415926f / 180.0f;
    float sinX;
    float sinY;
    float sinZ;
    float cosX;
    float cosY;
    float cosZ;
    float mf[4][4];
    int i;
    int e1;
    int e2;
    int *ai;
    int *af;
    float unused1;
    float unused2;

    rx *= degreesToRadians;
    ry *= degreesToRadians;
    rz *= degreesToRadians;
    sinX = func_8004E9D0(rx);
    cosX = func_8005C4E0(rx);
    sinY = func_8004E9D0(ry);
    cosY = func_8005C4E0(ry);
    sinZ = func_8004E9D0(rz);
    cosZ = func_8005C4E0(rz);
    mf[0][0] = cosY * cosZ * sx;
    mf[0][1] = cosY * sinZ * sx;
    mf[0][2] = -sinY * sx;
    mf[0][3] = 0.0f;
    mf[1][0] = (sinX * sinY * cosZ - cosX * sinZ) * sy;
    mf[1][1] = (sinX * sinY * sinZ + cosX * cosZ) * sy;
    mf[1][2] = sinX * cosY * sy;
    mf[1][3] = 0.0f;
    mf[2][0] = (cosX * sinY * cosZ + sinX * sinZ) * sz;
    mf[2][1] = (cosX * sinY * sinZ - sinX * cosZ) * sz;
    mf[2][2] = cosX * cosY * sz;
    mf[2][3] = 0.0f;
    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[3][3] = 1.0f;

    ai = m;
    af = m + 8;
    for (i = 0; i < 4; i++) {
        e1 = mf[i][0] * 65536.0f;
        e2 = mf[i][1] * 65536.0f;
        *ai++ = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
        *af++ = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
        e1 = mf[i][2] * 65536.0f;
        e2 = mf[i][3] * 65536.0f;
        *ai++ = (e1 & 0xFFFF0000) | ((e2 >> 16) & 0xFFFF);
        *af++ = ((e1 << 16) & 0xFFFF0000) | (e2 & 0xFFFF);
    }
}
