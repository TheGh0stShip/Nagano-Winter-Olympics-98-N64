typedef struct Tbl {
    unsigned char pad0[0x180];
    unsigned char ids[0x10];
    float vals[16];
} Tbl;

extern unsigned char *D_80126BF0;
extern Tbl D_80137150;
extern double D_800800C8;
extern float func_80029198(float a);

float func_80028DE0(float x) {
    float r;
    unsigned char i;
    unsigned char j;
    double c;
    float t;

    if (x < 0.0f) {
        return x;
    }
    for (i = 0; ; i++) {
        if (D_80126BF0[0x977EF] + 1 == D_80137150.ids[i]) {

            t = D_80137150.vals[i] + x;
            break;
        }
    }
    j = i;
    r = func_80029198(t);
    c = D_800800C8;
    r -= D_80137150.vals[j];
    r *= 100.0f;
    r += c;
    r = (unsigned int)r;
    r *= c;
    return r;
}
