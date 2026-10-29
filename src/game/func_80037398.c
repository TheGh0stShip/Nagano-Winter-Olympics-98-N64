extern void func_80036F4C(void *, unsigned short);
extern unsigned short func_80037040(void);
extern void func_80037C3C(void *, int);
extern unsigned char D_80072AF8;
extern unsigned char D_80137871;
long long D_80137880;
long long D_80137888;
int D_80137890;
float D_80137894;
long long D_80137898;
long long D_801378A0;
extern char D_80137958[];
extern char D_80137D70[];
extern char D_80137D98[];
extern unsigned char D_80137DE8;
extern unsigned char D_80138215;

void func_80037398(long long v) {
    unsigned short s;

    s = func_80037040();
    if (D_80072AF8 != 0 && D_80138215 != 1) {
        D_80137DE8 = 0x3C;
        D_80137871 = 1;
        D_80137898 = D_801378A0 = v;
        func_80037C3C(D_80137D70, 6);
        func_80037C3C(D_80137D98, 0);
        func_80036F4C(D_80137958, s);
    }
}
