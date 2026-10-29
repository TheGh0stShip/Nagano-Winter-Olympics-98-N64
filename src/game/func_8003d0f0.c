typedef struct {
    char pad[0x10];
    float y;
} Obj;

extern float D_80073084[];
extern char *D_80126BF0[];

void func_8003D0F0(float arg0) {
    int i;
    Obj *p;

    for (i = 0; i < 4; i++) {
        p = (Obj *)(D_80126BF0[i >> 2] + i * 0x138 + 0x853B0);
        if (i == 1) {
            continue;
        }
        p->y = D_80073084[i] + -64.0f * arg0;
    }
}
