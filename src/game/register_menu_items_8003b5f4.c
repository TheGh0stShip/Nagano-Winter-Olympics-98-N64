extern unsigned char *D_80126BF0;
extern unsigned char D_06002F88[];
extern unsigned char D_06002310[];
extern void func_80039544(unsigned char course);
extern void func_800389B4(int id);
extern void func_80039004(int id, float x, float y, int size, void *data, int kind);

int func_8003B5F4(int id) {
    func_80039544(D_80126BF0[0x977EC]);
    func_800389B4(id);
    id++;
    func_80039004(id++, -92.0f, 90.0f, 15, D_06002F88, 1);
    func_80039004(id++, -112.0f, 90.0f, 15, D_06002310, 1);
    return id;
}
