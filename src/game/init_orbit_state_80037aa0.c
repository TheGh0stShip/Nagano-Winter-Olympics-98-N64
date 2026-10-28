typedef struct Camera {
    int mode;
    int target;
    int unk8;
    int unkC;
    int unk10;
    float distance;
    float pitch;
    float yaw;
    float unk20;
    short active;
} Camera;

extern void func_80037560(Camera *camera);

void func_80037AA0(Camera *camera, int target, float yaw, float pitch, int mode) {
    camera->mode = mode;
    camera->target = target;
    camera->unk8 = 0;
    camera->unk10 = 0;
    camera->active = 1;
    camera->unkC = 0;
    camera->yaw = yaw;
    camera->pitch = pitch;
    camera->distance = 170.0f;
    camera->unk20 = 0.0f;
    func_80037560(camera);
}
