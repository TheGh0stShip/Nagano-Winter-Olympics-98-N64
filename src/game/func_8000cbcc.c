typedef struct DisplayCommand {
    unsigned int opcode;
    unsigned int argument;
} DisplayCommand;

typedef struct Keyframe {
    float x;
    float y;
    float z;
    float rx;
    float ry;
    float rz;
    float scale;
} Keyframe;

#define DISPLAY_COMMAND(pkt, op, arg) { DisplayCommand *_g = (pkt); _g->opcode = (op); _g->argument = (arg); }

extern DisplayCommand *D_8013356C;
extern int D_80133568;
extern void func_8005B020(void *output, float first, float second, float third,
                          float fourth, float fifth, float sixth, float seventh);

void func_8000CBCC(void *displayList, void *mtx, Keyframe *frames, int index, float t) {
    Keyframe *next;
    float rx;
    float ry;
    float rz;
    float x;
    float y;
    float z;
    float scale;

    frames += index;
    next = frames + 1;
    if (D_80133568 == 1) {
        next = frames;
    }
    rx = frames->rx + (next->rx - frames->rx) * t;
    ry = frames->ry + (next->ry - frames->ry) * t;
    rz = frames->rz + (next->rz - frames->rz) * t;
    x = frames->x + (next->x - frames->x) * t;
    y = frames->y + (next->y - frames->y) * t;
    z = frames->z + (next->z - frames->z) * t;
    scale = frames->scale + (next->scale - frames->scale) * t;
    scale *= 0.01;
    func_8005B020(mtx, x, y, z, scale, rx, ry, rz);
    DISPLAY_COMMAND(D_8013356C++, 0x01040040, (unsigned int)mtx);
    DISPLAY_COMMAND(D_8013356C++, 0x06000000, (unsigned int)displayList);
    DISPLAY_COMMAND(D_8013356C++, 0xBD000000, 0);
}
