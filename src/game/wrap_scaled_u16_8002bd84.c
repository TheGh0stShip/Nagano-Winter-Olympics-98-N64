unsigned short func_8002BD84(float value) {
    float scaled = (float)((double)value * 0.001);

    while (1) {
        if (scaled < 60.0f) {
            break;
        }
        scaled -= 60.0f;
    }
    return (unsigned short)scaled;
}
