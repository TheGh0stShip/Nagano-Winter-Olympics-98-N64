typedef struct VectorOwner {
    unsigned char pad[0x28];
    float vector[3];
} VectorOwner;

extern VectorOwner *D_80138684;
extern float D_80138688;
extern float D_8013868C;
extern float D_80138690;

void func_80046BFC(void) {
    D_80138688 = D_80138684->vector[0];
    D_8013868C = D_80138684->vector[1];
    D_80138690 = D_80138684->vector[2];
}
