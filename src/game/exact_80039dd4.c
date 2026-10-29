extern float D_801381F8;
extern float D_801381C0[8];
extern unsigned char D_801381E8[8];
extern int D_80072AF4;
extern float func_80039ACC(float x);

int func_80039DD4(void) {
    int i;
    int count;
    float x;
    float r;
    int base = 220;
    int range = 340;
    int n = 8;

    count = 8;
    for (i = 0; i < n; i++) {
        x = D_801381F8 - (8 - i) * 0.3141592653589793;
        if (x <= 0.0f) {
            count--;
        }
        r = func_80039ACC(x);
        D_801381C0[i] = base - range * r;
        D_801381E8[i] = D_80072AF4 * r;
    }
    return count;
}
