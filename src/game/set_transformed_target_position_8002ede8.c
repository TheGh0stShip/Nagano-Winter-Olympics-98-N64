typedef struct Position2EDE8 {
    unsigned char pad[4];
    float x;
    float y;
    float z;
} Position2EDE8;

extern unsigned char D_80137555;
extern unsigned char D_80071D70[];
extern short D_80071D7C[][3][3];
extern unsigned char *D_80126BF0;
extern float D_80071E10[];
extern float D_80137528[3];
extern void func_8002F438(float x, float y, float z,
                          float *outX, float *outY, float *outZ);

void func_8002EDE8(unsigned char index, int course) {
    Position2EDE8 *position = (Position2EDE8 *)(D_80126BF0 + 0x7FB28);
    float z;
    float y;
    float x;
    course = D_80071D70[D_80137555];

    func_8002F438(D_80071D7C[course][index][0],
                  D_80071D7C[course][index][1],
                  D_80071D7C[course][index][2],
                  &x, &y, &z);
    position->x = D_80137528[0] + D_80071E10[D_80137555] * x;
    position->y = D_80137528[1] + D_80071E10[D_80137555] * y;
    position->z = D_80137528[2] + D_80071E10[D_80137555] * z;
}
