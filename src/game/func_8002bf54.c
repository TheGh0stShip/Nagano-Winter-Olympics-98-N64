typedef struct Runtime {
    unsigned char pad0[0x977EC];
    unsigned char mode;
} Runtime;

extern Runtime *D_80126BF0;
extern signed char D_80071A50[];
extern unsigned int D_80071B58[];
extern double D_80080128;

unsigned short func_8002BF54(float val, unsigned char digits) {
    unsigned short i = 1;
    unsigned short d;
    int pad[8];
    unsigned short result;
    unsigned int step;
    unsigned int total;
    unsigned int rem;
    float f;

    if (D_80071A50[D_80126BF0->mode] < 0) {
        f = val;
        for (; i < digits; i++) {
            f *= 10.0f;
        }
        return (unsigned int)(float)((f - (unsigned int)(unsigned short)(unsigned int)f) * 10.0f + D_80080128);
    }
    total = 0;
    rem = (unsigned int)val % (D_80071B58[digits] * 10);
    for (d = 0; d < 10; d++) {
        total += D_80071B58[digits];
        if (rem < total) {
            result = d;
            break;
        }
    }
    return result;
}

