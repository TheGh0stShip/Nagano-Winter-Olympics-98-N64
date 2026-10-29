typedef struct Line {
    float x0;
    float pad4;
    float y0;
    float x1;
    float pad10;
    float y1;
} Line;

extern unsigned char D_80136C9D;
extern Line D_8019D390[];

float func_800212B4(float x, float y) {
    Line *line;
    float t[7];
    float y0;
    float m;
    float dx;

    m = x;
    if (m) {}
    if (x) {}
    if (y) {}
    if (*(int *)&D_8019D390[D_80136C9D].y1) {}
    line = &D_8019D390[D_80136C9D];
    y0 = line->y0;
    m = D_8019D390[D_80136C9D].y1 - y0;
    t[0] = line->x0;
    dx = line->x1 - t[0];
    t[2] = m / dx;
    t[6] = y0 - t[2] * t[0];
    return t[6] + t[2] * x - y;
}
