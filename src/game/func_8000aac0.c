typedef struct Camera {
    unsigned char limit;
    unsigned char count;
    unsigned char pad_02[0x12];
    float windX;
    float windZ;
} Camera;

typedef struct Flake {
    float x;
    float y;
    float z;
    float speed;
    unsigned short active;
    unsigned short pad_12;
} Flake;

extern Camera D_80131920;
extern Flake D_80131940[];
extern int func_8000B99C(void);
extern void func_8000AEB4(void);

void func_8000AAC0(void) {
    Flake *flake;
    short i;
    float bound;
    int sz;

    bound = 300.0f;
    sz = sizeof(Flake);

    if (D_80131920.count < D_80131920.limit) {
        if (func_8000B99C() < (unsigned short)(75.85185f * (unsigned int)D_80131920.limit / (4.0f / 2.0f))) {
            i = 0;
            while (D_80131940[i].active != 0) {
                i++;
            }
            flake = (Flake *)((char *)D_80131940 + i * sz);
            flake->active = 1;
            flake->x = (float)(func_8000B99C() % 400) - 199.5f;
            flake->y = bound;
            flake->z = (float)(func_8000B99C() % 400) - 199.5f;
            flake->speed = (unsigned int)func_8000B99C() / 32768.0f * (0.08f - 0.05f) + 0.05f;
            D_80131920.count++;
        }
    }
    for (i = 0; i < D_80131920.count; i++) {
        if (i) {}
        flake = (Flake *)((char *)D_80131940 + i * sz);
        flake->y -= 1.2f;
        flake->x += D_80131920.windX + ((unsigned int)func_8000B99C() / 32768.0f - 0.5f);
        flake->z += D_80131920.windZ + ((unsigned int)func_8000B99C() / 32768.0f - 0.5f);
        if (flake->y < -bound) {
            flake->y = bound;
        }
        if (flake->x < -bound) {
            flake->x = bound;
        }
        if (flake->x > bound) {
            flake->x = -bound;
        }
        if (flake->z < -bound) {
            flake->z = bound;
        }
        if (flake->z > bound) {
            flake->z = -bound;
        }
    }
    func_8000AEB4();
}
