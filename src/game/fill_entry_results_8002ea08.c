extern unsigned char D_8013755D;
extern unsigned char func_8002F67C(unsigned char index);

void func_8002EA08(unsigned char *out) {
    unsigned char i;

    for (i = 0; i < 5; i++) {
        out[i] = 0xFF;
    }
    for (i = 0; i < D_8013755D; i++) {
        out[i] = func_8002F67C(i);
    }
}
