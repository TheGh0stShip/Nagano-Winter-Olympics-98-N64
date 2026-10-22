typedef struct { float x, y, z; } Vec3f;
void func_80008650(void *object, float x, float y, float z) { Vec3f *v = (Vec3f *)((char *)object + 0x10); v->x = x; v->y = y; v->z = z; }
