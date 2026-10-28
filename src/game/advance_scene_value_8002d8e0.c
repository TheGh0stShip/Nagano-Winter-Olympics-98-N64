typedef struct Scene {
    short active;
    unsigned char pad2[0xA];
    float distance;
} Scene;

extern unsigned char *D_80126BF0;
extern unsigned char D_8013750F;
extern float func_8002D738(Scene *scene);
extern unsigned char func_8002D5AC(Scene *scene);

int func_8002D8E0(void) {
    Scene *scene = (Scene *)(D_80126BF0 + 0x88338);

    scene->active = 1;
    scene->distance += func_8002D738(scene);
    D_8013750F = func_8002D5AC(scene);
    if (scene->distance >= 300.0f) {
        return 1;
    }
    return 0;
}
