typedef struct LightColor {
    unsigned char pad[8];
    unsigned char a0;
    unsigned char a1;
    unsigned char a2;
    unsigned char padB;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char padF;
    unsigned char r;
    unsigned char g;
    unsigned char b;
} LightColor;

extern float func_8002F700(float r, float g, float b);

void func_8002FB28(LightColor *output, int first, int second, int third,
                   int r, int g, int b) {
    while (func_8002F700((float)r, (float)g, (float)b) > 127.0f) {
        r = (int)((double)r * 0.9);
        g = (int)((double)g * 0.9);
        b = (int)((double)b * 0.9);
    }
    output->r = r;
    output->g = g;
    output->b = b;
    output->a0 = first;
    output->b0 = first;
    output->a1 = second;
    output->b1 = second;
    output->b2 = third;
    output->a2 = third;
}
