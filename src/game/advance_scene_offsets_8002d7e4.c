typedef struct Scene {
    short active;
    unsigned char pad2[0x12];
    float distance;
    unsigned char pad18[0x10];
    float offset;
} Scene;

extern unsigned char *D_80126BF0;
extern unsigned char D_8013750F;
extern float func_8002D6B0(Scene *scene);
extern float func_8002D738(Scene *scene);
extern unsigned char func_8002D5AC(Scene *scene);

int func_8002D7E4(void) {
    Scene *scene = (Scene *)(D_80126BF0 + 0x88338);

    scene->active = 1;
    scene->offset += func_8002D6B0(scene);
    scene->distance += func_8002D738(scene);
    D_8013750F = func_8002D5AC(scene);
    if (scene->distance >= 0.0f) {
        return 1;
    }
    return 0;
}
