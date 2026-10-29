typedef struct Orbit {
    unsigned char pad0[0x30];
    float dx;
    float dy;
    float dz;
    float angle;
    float prev_angle;
    float remaining;
} Orbit;

typedef struct ViewRecord {
    unsigned short active;
    unsigned char pad2[2];
    float x;
    float y;
    float z;
} ViewRecord;

extern unsigned char *D_80126BF0;
extern float func_8004E9D0(float);
extern float func_8005C4E0(float);

float func_8001EEF8(Orbit *orbit, float speed, float radius, unsigned char reverse) {
    float b;
    float a;

    orbit->prev_angle = orbit->angle;
    if (reverse) {
        orbit->angle = orbit->angle - speed;
        if (orbit->angle < 0.0f) {
            orbit->angle = orbit->angle + 360.0;
        }
    } else {
        orbit->angle = orbit->angle + speed;
        if (orbit->angle >= 360.0) {
            orbit->angle = orbit->angle - 360.0;
        }
    }
    a = func_8005C4E0(orbit->prev_angle * 3.141592654 / 180.0);
    b = func_8005C4E0(orbit->angle * 3.141592654 / 180.0);
    orbit->dx = radius * a - b * radius;
    a = func_8004E9D0((orbit->prev_angle + 180.0f) * 3.141592654 / 180.0);
    b = func_8004E9D0((orbit->angle + 180.0f) * 3.141592654 / 180.0);
    orbit->dz = radius * a - b * radius;
    ((ViewRecord *)(D_80126BF0 + 0x7FB28))->x -= orbit->dx;
    ((ViewRecord *)(D_80126BF0 + 0x7FB28))->z -= orbit->dz;
    orbit->remaining -= speed;
    return orbit->remaining;
}
