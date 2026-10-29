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
extern void func_8002CA14(unsigned char index);

int func_8002C934(unsigned short scene_index, unsigned char table_index) {
    Scene *scene = (Scene *)(D_80126BF0 + 0x83EF8) + scene_index;

    scene->active = 1;
    scene->distance += func_8002CD14(scene->distance, table_index);
    D_801374E8[table_index] = func_8002CBE4(scene->distance, table_index);
    if (table_index == 4) {
        scene->distance = 1.0f;
    }
    if (scene->distance > 0.0f) {
        func_8002CA14(table_index);
        return 1;
    }
    return 0;
}
