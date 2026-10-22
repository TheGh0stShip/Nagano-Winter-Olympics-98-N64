typedef unsigned char u8;
typedef unsigned short u16;
extern u8 D_8013750E;
extern u16 D_80137512;
extern u8 func_8002D2DC(u16);
void func_8002D3E0(u8 value) {
    D_8013750E = value;
    D_8013750E = func_8002D2DC(D_80137512);
}
