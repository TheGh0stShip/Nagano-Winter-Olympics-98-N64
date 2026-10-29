unsigned char func_800465FC(float value) {
    float scaled = value * 6.5f;

    if (scaled > 250.0f) {
        scaled = 250.0f;
    } else if (scaled < 0.0f) {
        scaled = 0.0f;
    }
    return (unsigned char)scaled;
}
