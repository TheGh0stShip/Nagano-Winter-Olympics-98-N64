extern float func_8004E9D0(float value);
extern float func_8005C4E0(float value);

void func_8005AE70(float mf[4][4], float roll, float pitch, float yaw,
                   float scale, float x, float y, float z) {
    static float degreesToRadians = 3.1415926f / 180.0f;
    float sinRoll;
    float sinPitch;
    float sinYaw;
    float cosRoll;
    float cosPitch;
    float cosYaw;

    roll *= degreesToRadians;
    pitch *= degreesToRadians;
    yaw *= degreesToRadians;
    sinRoll = func_8004E9D0(roll);
    cosRoll = func_8005C4E0(roll);
    sinPitch = func_8004E9D0(pitch);
    cosPitch = func_8005C4E0(pitch);
    sinYaw = func_8004E9D0(yaw);
    cosYaw = func_8005C4E0(yaw);
    mf[0][0] = (cosPitch * cosYaw) * scale;
    mf[0][1] = (cosPitch * sinYaw) * scale;
    mf[0][2] = (-sinPitch) * scale;
    mf[0][3] = 0.0f;
    mf[1][0] = (sinRoll * sinPitch * cosYaw - cosRoll * sinYaw) * scale;
    mf[1][1] = (sinRoll * sinPitch * sinYaw + cosRoll * cosYaw) * scale;
    mf[1][2] = (sinRoll * cosPitch) * scale;
    mf[1][3] = 0.0f;
    mf[2][0] = (cosRoll * sinPitch * cosYaw + sinRoll * sinYaw) * scale;
    mf[2][1] = (cosRoll * sinPitch * sinYaw - sinRoll * cosYaw) * scale;
    mf[2][2] = (cosRoll * cosPitch) * scale;
    mf[2][3] = 0.0f;
    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[3][3] = 1.0f;
}
