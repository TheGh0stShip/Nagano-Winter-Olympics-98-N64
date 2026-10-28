typedef struct Camera {
    int mode;
    int target;
    int unk8;
    int unkC;
    int follow;
    float distance;
    float pitch;
    float yaw;
} Camera;

extern void func_800379B8(int target, float angle, float pitch, int mode);
extern void func_800377E8(int follow, float angle, float pitch);

void func_80037560(Camera *camera) {
    int follow = camera->follow;
    float angle;
    float pitch;
    int target;

    angle = camera->distance + camera->yaw;
    pitch = camera->pitch;
    target = camera->target;

    if (target >= 0) {
        func_800379B8(target, angle, pitch, camera->mode);
    }
    if (follow) {
        func_800377E8(follow, angle, pitch);
    }
}
