typedef struct Camera {
    unsigned char pad[0x20];
    float angle;
} Camera;

extern void func_80037C70(Camera *camera, float angle);

int func_80037CAC(Camera *camera) {
    int done = 0;

    camera->angle = camera->angle + 0.09424778335276407;
    if (camera->angle >= 1.5707963267948966) {
        camera->angle = 1.5707963267948966f;
        done = 1;
    }
    func_80037C70(camera, camera->angle);
    return done;
}
