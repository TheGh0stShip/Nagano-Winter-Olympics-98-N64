extern unsigned char D_80137555;
extern unsigned char D_8013755D;
extern float D_80071DE0[];
extern void func_8002EA98(unsigned char index);
extern int func_8002EF28(float limit);

int func_8002E804(int arg0) {
    unsigned char i;
    float limit = D_80071DE0[D_80137555];

    for (i = 0; i < D_8013755D; i++) {
        func_8002EA98(i);
    }
    if (func_8002EF28(limit)) {
        return 1;
    }
    return 0;
}
