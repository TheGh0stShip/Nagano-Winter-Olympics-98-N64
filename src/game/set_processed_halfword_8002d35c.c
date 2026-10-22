extern unsigned short D_80137512;
extern int func_8002D2B4(unsigned short);

void func_8002D35C(unsigned short value) {
    D_80137512 = value;
    D_80137512 = func_8002D2B4(D_80137512);
}
