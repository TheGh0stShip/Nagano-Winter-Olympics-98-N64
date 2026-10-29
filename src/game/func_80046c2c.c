typedef struct { int unk0; float x; float y; float z; char pad[0x18]; float rx; float ry; float rz; } Obj;
extern float func_80005550(float, float);
extern float func_8004E9D0(float);
extern float func_8005C4E0(float);
extern float D_8013843C;
extern float D_80138440;
extern float D_80138444;
extern float D_80138448;
extern double D_80138570;
extern int D_80138680;
extern Obj *D_80138684;
extern float D_80138688;
extern float D_8013868C;
extern float D_80138690;

int func_80046C2C(void) {
    float inv;
    float x;
    float y;
    float z;
    float ta;
    float tb;
    float tc;

    x = D_80138684->x;
    y = D_80138684->y;
    z = D_80138684->z;
    func_8005C4E0(D_80138448 / D_80138680 * D_80138570 / 2);
    x -= (1.0f - func_8005C4E0(D_80138448 / D_80138680 * D_80138570 / 2)) * (x - D_8013843C);
    y -= (1.0f - func_8005C4E0(D_80138448 / D_80138680 * D_80138570 / 2)) * (y - D_80138440);
    z -= (1.0f - func_8005C4E0(D_80138448 / D_80138680 * D_80138570 / 2)) * (z - D_80138444);
    D_80138684->x = x;
    D_80138684->y = y;
    D_80138684->z = z;
    x = D_80138684->rx * 2 * D_80138570 / 360.0;
    y = D_80138684->ry * 2 * D_80138570 / 360.0;
    z = D_80138684->rz * 2 * D_80138570 / 360.0;
    ta = D_80138688 * 2 * D_80138570 / 360.0;
    tb = D_8013868C * 2 * D_80138570 / 360.0;
    tc = D_80138690 * 2 * D_80138570 / 360.0;
    inv = 1.0f - D_80138448 / D_80138680;
    x = func_80005550(func_8004E9D0(ta) + (func_8004E9D0(x) - func_8004E9D0(ta)) * inv, func_8005C4E0(ta) + (func_8005C4E0(x) - func_8005C4E0(ta)) * inv);
    y = func_80005550(func_8004E9D0(tb) + (func_8004E9D0(y) - func_8004E9D0(tb)) * inv, func_8005C4E0(tb) + (func_8005C4E0(y) - func_8005C4E0(tb)) * inv);
    z = func_80005550(func_8004E9D0(tc) + (func_8004E9D0(z) - func_8004E9D0(tc)) * inv, func_8005C4E0(tc) + (func_8005C4E0(z) - func_8005C4E0(tc)) * inv);
    D_80138684->rx = x * 360.0f / 2 / D_80138570;
    D_80138684->ry = y * 360.0f / 2 / D_80138570;
    D_80138684->rz = z * 360.0f / 2 / D_80138570;
    if (D_80138448 > 0.0f) {
        D_80138448 -= 1.0f;
    }
    return D_80138448 == 0.0f ? 0 : 1;
}
