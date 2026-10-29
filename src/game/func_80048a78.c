extern unsigned char D_80179669;
extern unsigned char D_80179740;
extern unsigned char D_80179741;
extern unsigned char D_8017973F;
extern unsigned short D_80179748[];
void func_80048A78(unsigned short arg0) {
    int i; int n; unsigned char *p;
    if (arg0 >= 0x200) { D_80179669 = 0xFF; p = &D_80179740; if (p[0] < 9) { i = p[0]; n = i; i += p[1]; if (i >= 9) i -= 9; D_80179748[i] = arg0; n++; p[0] = n; } D_80179669 = 0; }
}
