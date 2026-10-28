double func_80057118(double value, int *exponent) {
    double absolute;

    *exponent = 0;
    if (value == 0.0) {
        return value;
    }
    absolute = (value > 0.0) ? value : -value;
    for (; absolute >= 1.0; absolute *= 0.5) {
        ++*exponent;
    }
    for (; absolute < 0.5; absolute += absolute) {
        --*exponent;
    }
    return value > 0.0 ? absolute : -absolute;
}
