unsigned char func_8004646C(float value) {
    float scaled = value * 1.4f;

    if (scaled > 250.0f) {
        scaled = 250.0f;
    } else if (scaled < 0.0f) {
        scaled = 0.0f;
    }
    return (unsigned char)scaled;
}
