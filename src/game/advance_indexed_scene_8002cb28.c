typedef struct Scene {
    short active;
    unsigned char pad2[0xA];
    float distance;
    unsigned char pad10[0x128];
} Scene;

extern unsigned char *D_80126BF0;
extern unsigned char D_801374E8[];
extern float func_8002CD14(float value, unsigned char index);
extern unsigned char func_8002CBE4(float value, unsigned char index);

int func_8002CB28(unsigned short sceneIndex, unsigned char tableIndex) {
    Scene *scene = (Scene *)(D_80126BF0 + 0x83EF8) + sceneIndex;

    scene->active = 1;
    scene->distance += func_8002CD14(scene->distance, tableIndex);
    D_801374E8[tableIndex] = func_8002CBE4(scene->distance, tableIndex);
    if (scene->distance > 300.0f) {
        return 1;
    }
    return 0;
}
