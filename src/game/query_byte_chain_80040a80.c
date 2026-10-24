extern short func_80040B90(unsigned char value);
extern short func_80040C70(unsigned char value, int context);
extern short func_80040DBC(unsigned char value);

short func_80040A80(unsigned char value, int context) {
    short result = func_80040B90(value);

    if (result == 0) {
        result = func_80040C70(value, context);
        if (result == 0) {
            result = func_80040DBC(value);
        }
    }
    return result;
}
