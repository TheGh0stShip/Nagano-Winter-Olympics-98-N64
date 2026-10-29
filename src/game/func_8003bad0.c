typedef struct Game {
    char pad[0x977F1];
    unsigned char unk977F1;
} Game;

extern void func_8003889C(float x, float y, int value, int id, int digits);
extern float func_80039ACC(float t);
extern void func_8003EBD0(int id, float sx, float sy);
extern void func_8003EC10(int id, float x, float y, unsigned short color);
extern int D_80072AF4;
extern unsigned char D_80072AFC;
extern Game *D_80126BF0;
extern float D_801381F8;
extern float D_80138208;
extern unsigned char D_80138214;

int func_8003BAD0(int id, int mode) {
    float t;
    float off;
    float scale;
    float base;
    float x;
    float lx;
    float x2;
    float y;
    float sx;
    float sy;
    float y2;
    float h;

    t = 1.0f - func_80039ACC(D_801381F8);
    base = 90.0f;
    scale = 100.0f;
    off = 0.0f;
    x = (int)D_80138208;
    x2 = x;
    if (D_80126BF0->unk977F1 == 0x15) {
        x2 = 0;
    }
    if (D_80072AFC != 0 && D_80072AFC != 3 && D_80072AFC != 5) {
        t = 0;
    }
    if (mode == 1) {
        y2 = (int)(-93.0f - 200.0f * t);
        h = 100.0f * t;
        if (D_80138214 != 7) {
            scale = 400.0f;
        }
        func_8003889C(x, (int)(h + 42.0f), D_80072AF4, id++, 2);
        func_8003889C(x, y2, D_80072AF4, id++, 2);
        func_8003EC10(id, x, y2, 1);
        id++;
        func_8003EC10(id, -50.0f + x, h + 49.0f, 1);
        id++;
        func_8003EC10(id, 86.0f + x, h + 46.0f, 1);
        off = -38.0f;
        id++;
    }
    h = 100.0f * t;
    if (D_80138214 >= 4) {
        off = -37.0f;
        base = 43.0f;
    }
    y = (int)(scale * t + base);
    if (D_80138214 == 7) {
        y = 90.0f;
    }
    func_8003889C(x2, y, D_80072AF4, id++, 1);
    lx = -92.0f;
    if (D_80138214 == 2 || D_80138214 == 7) {
        lx = -128.0f;
    }
    sx = x2 + lx;
    func_8003EC10(id, sx, y, 1);
    id++;
    func_8003EC10(id, -112.0f + x, (float)(int)(h + 90.0f) + off, 1);
    func_8003EBD0(id, 0.5f, 0.5f);
    id++;
    if (D_80126BF0->unk977F1 == 0x15 && D_80072AFC == 0) {
        sy = y - 1.0f;
        func_8003EC10(id, 120.0f + x2, sy, 1);
        id++;
    }
    return id;
}
