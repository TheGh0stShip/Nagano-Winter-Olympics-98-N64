typedef struct { float x, y, z; } Vec3f;
void func_80008670(void *object, float x, float y, float z) { Vec3f *v = (Vec3f *)((char *)object + 0x1C); v->x = x; v->y = y; v->z = z; }
