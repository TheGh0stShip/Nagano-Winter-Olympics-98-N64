typedef struct { float x, y, z, w, q; } Values;
void func_80021298(void *dst, Values *src) { char *p = dst; *(float *)(p + 0x38) = src->z; *(float *)(p + 0x3C) = src->w; *(float *)(p + 0x40) = src->q; }
