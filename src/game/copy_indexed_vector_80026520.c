typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Course {
    Vec3 points[3];
} Course;

typedef struct Out {
    unsigned char pad[8];
    Vec3 position;
} Out;

extern unsigned char D_80136C9D;
extern Course D_800715A0[];

void func_80026520(unsigned char course, Out *out) {
    out->position.x = D_800715A0[course].points[D_80136C9D].x;
    out->position.y = D_800715A0[course].points[D_80136C9D].y;
    out->position.z = D_800715A0[course].points[D_80136C9D].z;
}
