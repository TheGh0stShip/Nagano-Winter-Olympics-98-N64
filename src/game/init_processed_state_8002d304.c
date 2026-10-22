extern unsigned char D_8013750D;
extern unsigned char D_8013750E;
extern unsigned char D_8013750F;
extern unsigned short D_80137510;
extern unsigned short D_80137512;
extern int func_8002D2B4(unsigned short);

void func_8002D304(void) {
    D_8013750E = 10;
    D_80137510 = 0;
    D_8013750D = 0;
    D_8013750F = 0;
    D_80137512 = 60;
    D_80137512 = func_8002D2B4(D_80137512);
}
