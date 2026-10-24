typedef struct Output {
    unsigned char pad0[8];
    float index;
} Output;

extern unsigned char D_8006F640[][10];

void func_8001A508(Output *output, unsigned short index,
                   unsigned char source[20]) {
    unsigned short i;

    for (i = 0; i < 20; i++) {
        D_8006F640[index][i] = source[i];
    }
    output->index = index;
}
