extern void *func_8003AC84(void *output, int index, int a, float b, int c);

extern int D_801381C0[];
extern float D_801381E0;
extern unsigned char D_801381E8[];

void *func_8003C498(void *output, int index, int count, int offset) {
    int i;

    for (i = 0; i < count; i++) {
        output = func_8003AC84(output, index + i, D_801381C0[i], (float)offset + D_801381E0, D_801381E8[i]);
    }
    return output;
}
