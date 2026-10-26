typedef struct RuntimeBytes {
    unsigned char pad[0x92C78];
    unsigned char values[];
} RuntimeBytes;

extern unsigned char *D_80126BF0;
extern unsigned short D_801376C0;

void func_80031F84(void) {
    ((RuntimeBytes *)D_80126BF0)->values[D_801376C0] = 15;
    D_801376C0++;
    if (D_801376C0 >= 15000) {
        D_801376C0 = 14996;
    }
}
