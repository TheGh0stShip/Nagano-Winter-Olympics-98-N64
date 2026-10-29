typedef struct Obj {
    short type;
    short pad2;
    float pad4;
    float x;
    float y;
    float z;
    float a;
    float b;
    float c;
    unsigned char pad20[0x408];
} Obj;

extern unsigned char *D_80126BF0;
extern unsigned char D_80137555;
extern short D_80071DB4[][3];
extern short D_80071DC8[][3];
extern float D_80137528[4];
extern void func_8002F438(float a, float b, float c, float *x, float *y, float *z);

void func_8002F2B4(unsigned char n) {
    float r[4];
    float v[3];
    Obj *o;
    unsigned short i;

    o = (Obj *)(D_80126BF0 + 0x802A8) + n;

    if (D_80137555 == 11) {
        for (i = 0; i < 3; i++) { v[i] = D_80071DC8[n][i]; }
    } else {
        for (i = 0; i < 3; i++) { v[i] = D_80071DB4[n][i]; }
    }
    func_8002F438(v[0], v[1], v[2], &r[0], &r[1], &r[2]);
    o->x = D_80137528[0] + r[0];
    o->y = D_80137528[1] + r[1];
    o->z = D_80137528[2] + r[2];
    o->a = 0.0f;
    o->b = D_80137528[3];
    o->type = 15;
    o->c = 0.0f;
}
