typedef struct Source {
    int pad0;
    float x;
    float y;
    float z;
} Source;

extern int D_80138680;
extern Source *D_80138684;
extern float D_8013843C;
extern float D_80138440;
extern float D_80138444;
extern float D_80138448;

void func_80046BA4(Source *source, int value) {
    D_80138680 = value;
    D_80138684 = source;
    D_8013843C = D_80138684->x;
    D_80138440 = D_80138684->y;
    D_80138444 = D_80138684->z;
    D_80138448 = D_80138680;
}
