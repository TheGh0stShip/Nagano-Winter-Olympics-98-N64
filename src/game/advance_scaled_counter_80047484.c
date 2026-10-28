extern int D_80138660;
extern unsigned long long func_800541B8(float value);

unsigned short func_80047484(void) {
    D_80138660 = (unsigned short)func_800541B8(D_80138660 * 665.0f + 3.0f) % 65536;
    return D_80138660;
}
