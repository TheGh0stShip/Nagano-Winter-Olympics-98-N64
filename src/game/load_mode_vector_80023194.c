typedef struct Vector {
    unsigned int pad0;
    float x;
    float y;
    float z;
} Vector;

extern unsigned char D_80136C9D;
extern float D_800704D0[][3];
extern float D_80070614[][3];
extern float D_8007074C[][3];

void func_80023194(unsigned char index, Vector *output) {
    output->x = D_800704D0[index][D_80136C9D];
    output->y = D_80070614[index][D_80136C9D];
    output->z = D_8007074C[index][D_80136C9D];
}
