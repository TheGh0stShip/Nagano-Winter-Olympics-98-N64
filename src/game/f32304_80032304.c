extern short D_80137706;
extern unsigned char *D_80126BF0;
extern void func_800348FC(int);
extern void func_80034958(float);
extern void func_8003492C(int);

short func_80032304(void) {
    short result = 0;
    short i;

    if (D_80137706 < 10) {
        for (i = 0; i < 4; i++) {
            func_800348FC((unsigned char)(i + 0x20));
        }
        func_80034958(-60.0f);
        func_8003492C(0);
    } else if (D_80137706 == 10) {
        for (i = 0; i < 0x5F; i++) {
            *(short *)(D_80126BF0 + i * 0x138 + 0x83EF8) = 0;
        }
    } else if (D_80137706 >= 14) {
        result = 1;
    }
    D_80137706 = D_80137706 + 1;
    return result;
}
