typedef struct ColorOutput {
    unsigned char pad[8];
    unsigned char r;
    unsigned char g;
    unsigned char b;
} ColorOutput;

extern float func_8002F700(float r, float g, float b);

void func_8002F7BC(int r, int g, int b, ColorOutput *output) {
    while (func_8002F700((float)r, (float)g, (float)b) > 127.0f) {
        r = (int)((double)r * 0.9);
        g = (int)((double)g * 0.9);
        b = (int)((double)b * 0.9);
    }
    output->r = r;
    output->g = g;
    output->b = b;
}
