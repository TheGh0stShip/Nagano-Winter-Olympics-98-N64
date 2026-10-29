typedef struct RuntimeObject {
    unsigned char pad[0x19C];
    unsigned short first;
    unsigned short second;
} RuntimeObject;

typedef struct InputRun {
    unsigned short buttons;
    short count;
} InputRun;

typedef struct Pad {
    unsigned short state;
    unsigned short held1;
    unsigned short held2;
    unsigned short pad6[2];
    unsigned short pressed1;
    unsigned short pressed2;
} Pad;

typedef struct Runtime {
    unsigned char pad0[0x7C8F4];
    Pad pads[7880];
    unsigned char pad977E4[0xB];
    unsigned char player;
} Runtime;

extern Runtime *D_80126BF0;

void func_8001F618(RuntimeObject *object) {
    InputRun *first = (InputRun *)((unsigned char *)D_80126BF0 + 0x92C78);
    InputRun *second = (InputRun *)((unsigned char *)D_80126BF0 + 0x949C4);

    if (object->first < 1875U) {
        first += object->first;
        if (first->buttons == (D_80126BF0->pads[D_80126BF0->player].held1 | D_80126BF0->pads[D_80126BF0->player].pressed1)) {
            first->count++;
        } else {
            object->first++;
            first++;
            first->buttons = D_80126BF0->pads[D_80126BF0->player].held1 + D_80126BF0->pads[D_80126BF0->player].pressed1;
            first->count++;
        }
    }
    if (object->second < 1875U) {
        second += object->second;
        if (second->buttons == (D_80126BF0->pads[D_80126BF0->player].held2 | D_80126BF0->pads[D_80126BF0->player].pressed2)) {
            second->count++;
        } else {
            object->second++;
            second++;
            second->buttons = D_80126BF0->pads[D_80126BF0->player].held2 + D_80126BF0->pads[D_80126BF0->player].pressed2;
            second->count++;
        }
    }
}
