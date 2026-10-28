extern unsigned char *D_80126BF0;
extern int D_801330B4;
extern int D_801330BC;
extern int D_801330C0;
extern void func_8000C098(unsigned char *data);

unsigned char *func_8000C014(unsigned char *data) {
    D_801330B4++;
    D_801330C0--;
    D_801330BC--;
    if (D_801330C0 != 0) {
        data++;
    } else {
        data = D_80126BF0 + 0x967E0;
        func_8000C098(data);
    }
    return data;
}
