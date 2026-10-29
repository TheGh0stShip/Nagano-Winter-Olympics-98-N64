extern float D_801381F8;
extern float D_80138208;
extern unsigned char D_80072AFC;
extern int D_80072AF4;
extern float func_80039ACC(float);
extern void func_8003889C(float, float, int, int, int);
extern int func_8003EC10(int, float, float, int);
extern void func_8003EBD0(int, float, float);

int func_8003B984(int index) {
    float fade;
    float pad2;
    float height;
    float pos;
    float x;
    float pad[4];
    x = 0.0f;
    fade = 1.0f - func_80039ACC(D_801381F8);
    height = (float)(int)D_80138208;
    if (D_80072AFC != 0 && D_80072AFC != 3 && D_80072AFC != 5) {
        fade = 0.0f;
    }
    pos = (float)(int)(100.0f * fade + 90.0f);
    func_8003889C(0.0f, pos, D_80072AF4, index++, 1);
    func_8003EC10(index, x + -92.0f, pos, 1);
    func_8003EC10(++index, -112.0f + height, pos, 1);
    func_8003EBD0(index, 0.5f, 0.5f);
    return index + 1;
}
