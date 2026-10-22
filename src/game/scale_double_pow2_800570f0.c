double func_800570F0(double value, int shift) {
    if (shift != 0) {
        value *= (double)(1 << shift);
    }
    return value;
}
