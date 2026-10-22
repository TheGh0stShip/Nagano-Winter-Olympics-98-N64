typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

extern Vector3 D_80134020[];
extern int D_80134018;

void func_8000FCF4(void) {
    unsigned char i;

    for (i = 0; i < 6; i++) {
        D_80134020[i].x = 300.0f;
        D_80134020[i].y = 0.0f;
        D_80134020[i].z = 0.0f;
    }
    D_80134018 = 0;
}
