typedef struct Target {
    unsigned char pad[0xC];
    float x;
    float y;
} Target;

extern float D_80072AE8;

void func_80036F58(Target **target, float x, float y) {
    if (*target != 0) {
        (*target)->x = (int)x + (int)x / D_80072AE8;
        (*target)->y = (int)y + (int)y / D_80072AE8;
    }
}
