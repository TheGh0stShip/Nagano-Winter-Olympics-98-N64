typedef struct RuntimeObject {
    unsigned char pad[0x19C];
    unsigned short first;
    unsigned short second;
} RuntimeObject;

typedef struct InputRun {
    unsigned short buttons;
    short count;
} InputRun;

typedef struct InputState {
    unsigned char pad0[0x48F4];
    unsigned short state;
    unsigned short held1;
    unsigned short held2;
    unsigned short pad6[2];
    unsigned short pressed1;
    unsigned short pressed2;
} InputState;

extern unsigned char *D_80126BF0;

void func_8001F790(RuntimeObject *object) {
    InputRun *first = (InputRun *)(D_80126BF0 + 0x92C78);
    InputRun *second = (InputRun *)(D_80126BF0 + 0x949C4);

    first += object->first;
    if (first->count == 0) {
        object->first++;
        first++;
    }
    ((InputState *)(D_80126BF0 + D_80126BF0[0x977EF] * 14 + 0x78000))->held1 = first->buttons;
    ((InputState *)(D_80126BF0 + D_80126BF0[0x977EF] * 14 + 0x78000))->pressed1 = first->buttons;
    first->count--;
    second += object->second;
    if (second->count == 0) {
        object->second++;
        second++;
    }
    ((InputState *)(D_80126BF0 + D_80126BF0[0x977EF] * 14 + 0x78000))->held2 = second->buttons;
    ((InputState *)(D_80126BF0 + D_80126BF0[0x977EF] * 14 + 0x78000))->pressed2 = second->buttons;
    second->count--;
}
