extern unsigned char *D_80126BF0;
extern float D_80137320[];
extern float D_80137360[];
extern int func_8002B4B4(void);

void func_8002A300(float *value) {
    int index = func_8002B4B4();
    float v = *value;
    float result = v;

    if (v <= 0.0f) {
        result = 0.0f;
    }
    if (D_80126BF0[0x977F2] == 0) {
        D_80137320[index] = result;
    } else {
        D_80137360[index] = result;
    }
}
