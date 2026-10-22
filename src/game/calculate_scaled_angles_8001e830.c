extern float func_8004E9D0(float);
extern float func_8005C4E0(float);

void func_8001E830(unsigned short angle, float scale, float *first, float *second) {
    *second = func_8004E9D0((float)((double)angle * 3.141592654 / 180.0)) * scale;
    *first = func_8005C4E0((float)((double)angle * 3.141592654 / 180.0)) * scale;
}
