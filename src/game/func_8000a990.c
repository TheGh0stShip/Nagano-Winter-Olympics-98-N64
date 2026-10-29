typedef struct Camera {
    float field_00;
    float distance;
    float prevDistance;
    float scale;
    short index;
} Camera;

typedef struct View {
    unsigned char pad0[0x48];
    float fov;
    unsigned char pad4C[0x2C];
} View;

extern Camera D_80131920;
extern unsigned char *D_80126BF0;
extern float func_8004E9D0(float value);
extern float func_8005C4E0(float value);

void func_8000A990(float distance) {

    D_80131920.prevDistance = D_80131920.distance;
    if (distance < 200.0f) {
        D_80131920.distance = 200.0f;
    } else {
        D_80131920.distance = distance;
    }
    D_80131920.scale = D_80131920.distance * (4.0f / 2.0f) *
                       func_8004E9D0(((View *)(D_80126BF0 + 0x7FB20))[D_80131920.index].fov * 0.5f * 3.141592653589793 / 180.0) /
                       func_8005C4E0(((View *)(D_80126BF0 + 0x7FB20))[D_80131920.index].fov * 0.5f * 3.141592653589793 / 180.0) / 240.0f;
}
