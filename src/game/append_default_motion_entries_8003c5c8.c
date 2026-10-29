extern void *func_8003AF48(void *output, int index);

extern float D_801381C0[];
extern unsigned char D_801381E8[];
extern int D_80072AF4;

void *func_8003C5C8(void *output, int index, int count) {
    int i;
    int current;

    if (count > 0) {
#line 1000
        i = 0; current = index;
#line 20
        do {
            void *next = func_8003AF48(output, current);
            current++;
            i++;
            output = next;
            D_801381C0[i - 1] = -120.0f;
            D_801381E8[i - 1] = D_80072AF4;
        } while (i < count);
    }
    return output;
}
