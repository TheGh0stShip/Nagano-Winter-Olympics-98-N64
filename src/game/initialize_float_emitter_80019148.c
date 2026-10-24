typedef struct Vector {
    float x;
    float y;
    float z;
} Vector;

typedef struct Emitter {
    unsigned char pad0[4];
    signed short mode;
    unsigned char pad06[2];
    float intensity;
    unsigned char pad0C[0x29];
    unsigned char flag;
    unsigned char pad36[0x106];
    unsigned char vector_index;
    unsigned char pad13D[3];
    Vector *vector;
} Emitter;

extern unsigned char D_80135C01;
extern Vector D_80135D68[];

void func_80019148(Emitter *emitter, unsigned char intensity,
                   unsigned char flag, float x, float y, float z) {
    Vector *vector;

    emitter->flag = flag;
    emitter->mode = 0x2000;
    emitter->intensity = intensity;
    emitter->vector_index = D_80135C01;
    vector = &D_80135D68[D_80135C01++];
    vector->x = x;
    vector->y = y;
    vector->z = z;
    emitter->vector = vector;
}
