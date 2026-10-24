extern short func_80040C00(unsigned char value);
extern short func_80040E18(unsigned char value);

short func_80040A3C(unsigned char value) {
    short result = func_80040C00(value);

    if (result == 0) {
        result = func_80040E18(value);
    }
    return result;
}
