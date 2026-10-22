typedef struct { float x, y, z; } Vec3f;
void func_80008630(void *object, float x, float y, float z) { Vec3f *v = (Vec3f *)((char *)object + 4); v->x = x; v->y = y; v->z = z; }
