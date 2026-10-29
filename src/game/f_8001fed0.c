void func_8001FED0(unsigned short mode, float *v) {
    switch (mode) {
    case 1:
        v[1] = -v[1];
        v[5] = -v[5];
        v[3] = -v[3];
        break;
    case 2:
        v[2] = -v[2];
        v[3] = -v[3];
        break;
    case 3:
        v[0] = -v[0];
        v[3] = -v[3];
        v[3] += 180.0f;
        v[5] = -v[5];
        v[5] += 180.0f;
        break;
    }
}
