typedef struct Camera {
    unsigned char id;
    unsigned char field_01;
    unsigned char pad_02[2];
    float distance;
    float prevDistance;
    float scale;
    short index;
    short pad_12;
    float field_14;
    float field_18;
    short slot;
    unsigned char mode;
} Camera;

typedef struct View {
    unsigned char pad0[0x48];
    float fov;
    unsigned char pad4C[0x2C];
} View;

typedef struct Slot {
    unsigned short active;
    unsigned char pad_02[0xA];
    float field_0C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    unsigned char pad_30[0x108];
} Slot;

extern Camera D_80131920;
extern unsigned char *D_80126BF0;
extern unsigned char D_8006C4C4[];
extern int D_8006C4E8[];
extern unsigned char D_8006C500;
extern float func_8004E9D0(float value);
extern float func_8005C4E0(float value);
extern void func_800437A0(unsigned short, void *, int, unsigned short, int);

int func_8000A470(unsigned char id, short index, float distance, float arg3, float arg4,
                  unsigned char mode) {
    short i;
    int found;
    float table[5] = { 0.0f, 0.0f, 0.0f, 0.01f, 0.0f };

    found = 0;
    if (id < 301) {
        for (i = 94; i >= 0; i--) {
            if (((Slot *)(D_80126BF0 + 0x83EF8))[i].active == 0) {
                found = 1;
                D_80131920.slot = i;
                break;
            }
        }
    }
    if (found) {
        D_80131920.id = id;
    } else {
        return 1;
    }
    if (index < 16) {
        D_80131920.index = index;
    } else {
        return 2;
    }
    if (distance < 200.0f) {
        D_80131920.distance = 200.0f;
    } else {
        D_80131920.distance = distance;
    }
    D_80131920.scale = D_80131920.distance * (4.0f / 2.0f) *
                       func_8004E9D0(((View *)(D_80126BF0 + 0x7FB20))[D_80131920.index].fov * 0.5f * 3.141592653589793 / 180.0) /
                       func_8005C4E0(((View *)(D_80126BF0 + 0x7FB20))[D_80131920.index].fov * 0.5f * 3.141592653589793 / 180.0) / 240.0f;
    if (mode >= 4) {
        return 3;
    }
    func_800437A0(D_80131920.slot, D_8006C4C4, D_8006C4E8[mode], D_80131920.index, 0);
    if (D_80126BF0[0x977F1] != 0x18) {
        D_80131920.mode = mode;
    } else {
        D_80131920.mode = D_8006C500;
    }
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_0C = 0.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_10 = 0.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_14 = 0.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_18 = 0.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_1C = 0.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_20 = 0.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_24 = 1.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_28 = 1.0f;
    ((Slot *)(D_80126BF0 + 0x83EF8))[D_80131920.slot].field_2C = 1.0f;
    D_80131920.field_01 = 0;
    D_80131920.prevDistance = D_80131920.distance;
    D_80131920.field_14 = arg3;
    D_80131920.field_18 = arg4;
    return 0;
}
