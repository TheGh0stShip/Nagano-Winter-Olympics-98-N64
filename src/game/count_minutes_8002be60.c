unsigned short func_8002BE60(float value) {
    unsigned short count = 0;
    float v = value * 0.001;

    while (1) {
        v -= 60.0f;
        if (v >= 0.0f) {
            count++;
        } else {
            break;
        }
    }
    return count;
}
