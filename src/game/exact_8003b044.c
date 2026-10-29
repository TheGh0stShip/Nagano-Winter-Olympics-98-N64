extern unsigned char *D_80126BF0;
extern unsigned char D_80138218;
extern short D_8013821C;
extern unsigned char D_801376D0[];
extern unsigned char D_80137DE9;
extern unsigned char D_80137DEA;
extern unsigned char *D_800725B0[];
extern unsigned char *D_80072BB4[];
extern unsigned char *D_80072BA4[];
extern unsigned char *D_80072B64[];
extern int D_80072AEC;
extern float D_800806C8;
extern unsigned char D_06002370[];
extern int func_800389B4(int id);
extern void func_8003B020(void);
extern int func_80039004(int id, float x, float y, int size, void *data, int kind);
extern short func_80038E0C(int index);
extern void func_800375F0(int id, int a, float x, float y, float z, float w);
extern void func_8003EB80(int id, int value);

int func_8003B044(int id) {
    int index;

    if (D_80138218 == 0) {
        return id;
    }
    func_800389B4(id);
    id++;
    func_80039004(id, -170.0f, 0.0f, 7, D_800725B0[D_801376D0[D_80126BF0[0x977EF]]], 1);
    id++;
    func_800389B4(id);
    id++;
    func_800389B4(id);
    func_8003B020();
    id++;
    func_80039004(id, -170.0f, 0.0f, 7, D_80072BB4[D_80126BF0[0x977EF]], 1);
    id++;
    index = D_80126BF0[0x977EF] - D_80126BF0[0x977F0] + 4;
    if (index >= 3) {
        index = 3;
    }
    func_80039004(id, -170.0f, 0.0f, 7, D_80072BA4[index], 1);
    id++;
    D_8013821C = func_80038E0C(D_80126BF0[0x977EF]);
    if (D_8013821C >= 0 && D_8013821C < 16) {
        func_80039004(id, -170.0f, 0.0f, 7, D_80072B64[D_8013821C], 1);
    } else {
        func_8003EB80(id, 0);
    }
    id++;
    func_80039004(id, -170.0f, 0.0f, D_80072AEC, D_06002370, D_80137DE9);
    id++;
    func_800389B4(id);
    func_800375F0(id, 0x800, -170.0f, 0.0f, 7.0f, D_800806C8);
    func_8003EB80(id, D_80137DEA);
    return id + 1;
}
