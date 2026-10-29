extern float D_801366EC;
extern float D_8007ED3C;
extern void func_8001DE10(int width, int height);
extern void func_8001DFC0(int index, float first, float second);
extern void func_8001E1C8(int);

int func_8001D470(void) {
    float start;
    float end;
    float t;
    float r;
    float y;
    int w;
    int h;

    start = 56.0f;
    end = -200.0f;
    t = D_801366EC * D_8007ED3C;
    r = t / (start - end);
    if (1.0f < r) {
        r = 1.0f;
    }
    w = r * 64.0f + 256.0f;
    h = r * 112.0f + 128.0f;
    func_8001DE10(w, h);
    y = start - t;
    func_8001DFC0(0, 0.0f, y);
    if (y <= -54.0f) {
        func_8001E1C8(0);
    }
    if (y <= -142.0f) {
        func_8001E1C8(1);
    }
    if (y < end) {
        D_801366EC = 0.0f;
        return 1;
    }
    return 0;
}
