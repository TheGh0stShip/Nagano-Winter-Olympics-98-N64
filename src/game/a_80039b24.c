extern float D_801381F8;
extern float D_801381C0[];
extern unsigned char D_801381E8[];
extern int D_80072AF4;
extern unsigned char D_80072AFC;
extern float func_80039ACC(float);

int func_80039B24(void) {
    int n = 8;
    int count = 8;
    int i;
    float angle;
    float r;
    float prod;
    int cy = 220;
    int ch = 340;

    for (i = 0; i < n; i++) {
        angle = D_801381F8 - i * 0.3141592653589793;
        if (angle > 1.5707963267948966) {
            count--;
        }
        r = func_80039ACC(angle);
        D_801381C0[i] = cy - ch * r;
        if (D_80072AFC >= 4) {
            r = func_80039ACC(D_801381F8);
            if ((i & 1) == 1) {
                prod = 340.0f * r;
                D_801381C0[i] = -460.0f + prod;
            } else {
                D_801381C0[i] = cy - ch * r;
            }
        }
        D_801381E8[i] = D_80072AF4 * r;
    }
    return count;
}
