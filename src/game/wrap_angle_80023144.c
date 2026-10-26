void func_80023144(float *angle) {
    if (*angle > 360.0f) {
        *angle -= 360.0f;
    }
    if (*angle < -360.0f) {
        *angle += 360.0f;
    }
}
