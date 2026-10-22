typedef signed short s16;
void func_8001A570(void *object, s16 value, float scale) { char *p = object; *(s16 *)(p + 4) = value; *(float *)(p + 8) = scale; }
